import paho.mqtt.client as mqtt
import time, json, base64, datetime
import sqlite3 as database

def on_connect(client, userdata, flags, rc):
    if (rc==0):
        print("Connection OK")
        client.subscribe("application/1/device/1122334455667788/rx")
    else:
        logFile = open("errorlog.txt", 'a')
        logFile.write(str(datetime.datetime.now()) + " | " + "Connection Error Code: " + str(rc))
        logFile.close()
        print("Bas Connection code: ", rc)

def on_log(client, userdata, level, buf):
    print("log: ", buf)

def on_disconnect(client, userdata, flags, rc=0):
    print("Disconnected result Code: ", str(rc))

def on_message(client, userdata, msg):
    print("Message: " + str(msg.payload))
    message = str(msg.payload)[2:]
    message = message[:-1]
    jsonObject = json.loads(message)

    databaseConnection = database.connect("/home/yagizhan-ubuntu/Desktop/LoRa Network API/LoraNetworkAPI/db.sqlite3")
    cursor = databaseConnection.cursor()

    cursor.execute("CREATE TABLE IF NOT EXISTS LoraAPI_endnode (data varchar(200), rssiData varchar(200), snrData varchar(200), latitude varchar(200), longitude varchar(200), altitude varchar(200))")
    
    #get data
    data = jsonObject["data"]
    data = base64.b64decode(data)
    data = str(data)[2:-1]
    print("data: ", str(data))

    #get rssi
    rxInfo = jsonObject["rxInfo"][0]
    rssiData = rxInfo["rssi"]
    #print(str(rxInfo))
    print("RSSI Data: ", str(rssiData))

    #get SNR data
    snrData = rxInfo["loRaSNR"]
    print("SNR Data: ", str(snrData))

    #get location data
    locationInfo = rxInfo["location"]
    latitudeData = locationInfo["latitude"]
    print("Latitude Data: ", latitudeData)

    longitudeData = locationInfo["longitude"]
    print("Longitude Data: ", longitudeData)

    altitudeData = locationInfo["altitude"]
    print("Altitude Data: ", altitudeData)

    cursor.execute("INSERT INTO LoraAPI_endnode (timestamp, data, rssiData, snrData, latitude, longitude, altitude) VALUES (?, ?, ?, ?, ?, ?, ?)", (str(datetime.datetime.now()), str(data), str(rssiData), str(snrData), str(latitudeData), str(longitudeData), str(altitudeData)))
    #cursor.execute("INSERT INTO endnode_data VALUES (1, '08012020', 'BEYAZ', '12', '23', '0', '0', '0')")
    databaseConnection.commit()
    databaseConnection.close()

broker = "169.254.1.3"

client = mqtt.Client("Python")

client.on_connect = on_connect
client.on_log = on_log
client.on_disconnect = on_disconnect
client.on_message = on_message

print("Connecting to broker ", broker)
client.connect(broker)
client.loop_forever()
