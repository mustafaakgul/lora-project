
from influxdb import InfluxDBClient

import time, json, datetime
import sqlite3 as database

client = InfluxDBClient(host='localhost', port=8086)
#print(client.get_list_database())
client.switch_database('loranetworkserver')
result = client.query('SELECT * FROM device_frmpayload_data_mydata')
#print(result)
x=list(result.get_points(measurement='device_frmpayload_data_mydata'))
#print(len(x))
number=len(x)
print(number)

databaseConnection = database.connect('/home/lorawanadmin/Desktop/apiPublisher/db.sqlite3')
cursor = databaseConnection.cursor()
#cursor.execute('CREATE TABLE IF NOT EXISTS endnode_endnode (data varchar(200), rssiData varchar(200), snrData varchar(200))')

for element in x:
    timestamp4time=(element['time'])
    data=(element['value'])
    cursor.execute('INSERT INTO endnode_endnode (timestamp, data) VALUES (?,?)', (str(timestamp4time), str(data)))
    databaseConnection.commit()

databaseConnection.close()


'''
databaseConnection = database.connect('/home/Desktop/apiPublisher/db.sqlite3')
cursor = databaseConnection.cursor()

cursor.execute('INSERT INTO endnode_endnode (timestamp, data) VALUES (?,?)', (str(timestamp4time), str(data)))
databaseConnection.commit()
databaseConnection.close()
'''