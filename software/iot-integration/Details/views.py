from django.shortcuts import render, HttpResponse
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from .models import AddEndnode, AddGateway
from .serializers import AddEndnodeSerializer, EndnodeDetailsSerializer, AddGatewaySerializer
import json, requests

class AddEndnode(APIView):

    def get(self, request):

        endnodeDetails = EndnodeDetails.objects.all()
        serializer = EndnodeDetailSerializer(endnodeDetails, many=True)
        return Response(serializer.data)

    def post(self, request):

        serializer = AddEndnodeSerializer(data=request.data)
        requestData = request.data
        jsonObject = json.dumps(requestData)
        jsonObject = json.loads(jsonObject)
        token = GetTokenFromLoraAPI()
        profileID = GetProfileID(token, "1")
        createEndnodeResponse = CreateEndnode(token, jsonObject, profileID)
        if (serializer.is_valid() and createEndnodeResponse != "Error"):
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

def GetTokenFromLoraAPI():

    url = "http://169.254.1.3:8080/api/internal/login"

    data = '{"password":"admin", "username": "admin"}'

    headers = {
        'Content-Type': 'application/json',
        'Accept': 'application/json' 
    }

    response = requests.post(url, headers=headers, data=data)
    responseText = response.text
    token = json.loads(responseText)["jwt"]
    return token

def GetProfileID(token, applicationID):

    url = "http://169.254.1.3:8080/api/device-profiles?limit=1&applicationID={}".format(applicationID)

    headers ={
        "Grpc-Metadata-Authorization": str(token)
    }

    response = requests.get(url, headers=headers)

    jsonObject = json.loads(response.text)
    profileID = jsonObject["result"][0]["id"]
    
    return str(profileID)

def CreateEndnode(token, data, profileID):
    url = "http://169.254.1.3:8080/api/devices"

    data["deviceProfileID"] = profileID
    data = json.dumps({"device":data})

    print(data)

    headers ={
        "Grpc-Metadata-Authorization": str(token)
    }

    response = requests.post(url, headers=headers, data=data)

    print(response.status_code)

    if (response.status_code != 200):
        return "Error"
    else:
        return "Success"

class GetEndnodeDetails(APIView):

    def get(self, request, eui):
        
        deviceEui = eui

        url = "http://169.254.1.3:8080/api/devices/{}".format(deviceEui)

        token = GetTokenFromLoraAPI()

        headers ={
        "Grpc-Metadata-Authorization": str(token)
        }

        response = requests.get(url, headers=headers)

        jsonObject = json.dumps(response.text)
        jsonObject = json.loads(jsonObject)

        return HttpResponse(jsonObject, content_type='application/json; charset=UTF-8')

class GetEndnodeActivation(APIView):

    def get(self, request, eui):
        
        deviceEui = eui

        url = "http://169.254.1.3:8080/api/devices/{}/activation".format(deviceEui)

        token = GetTokenFromLoraAPI()

        headers ={
        "Grpc-Metadata-Authorization": str(token)
        }

        response = requests.get(url, headers=headers)

        jsonObject = json.dumps(response.text)
        jsonObject = json.loads(jsonObject)

        return HttpResponse(jsonObject, content_type='application/json; charset=UTF-8')

class GetGatewayDetails(APIView):

    def get(self, request, eui):

        deviceEui = eui

        print (deviceEui)

        url = "http://169.254.1.3:8080/api/gateways/{}".format(deviceEui)

        print(url)

        token = GetTokenFromLoraAPI()

        headers ={
        "Grpc-Metadata-Authorization": str(token)
        }

        response = requests.get(url, headers=headers)

        jsonObject = json.dumps(response.text)
        jsonObject = json.loads(jsonObject)

        return HttpResponse(jsonObject, content_type='application/json; charset=UTF-8')

class AddGateway(APIView):
    
    def post(self, request):

        serializer = AddGatewaySerializer(data=request.data)
        requestData = request.data
        jsonObject = json.dumps(requestData)
        jsonObject = json.loads(jsonObject)
        print("Json Data: " + str(jsonObject))
        token = GetTokenFromLoraAPI()
        profileID = GetGatewayProfilID(token)
        createGatewayResponse = CreateGateway(token, jsonObject, profileID)
        print(createGatewayResponse)
        if (createGatewayResponse != "Error"):
            return Response(status=status.HTTP_201_CREATED)
        else:
            return Response(status=status.HTTP_400_BAD_REQUEST)

def GetGatewayProfilID(token):

    url = "http://169.254.1.3:8080/api/gateway-profiles?limit=5&networkServerID=1"

    headers ={
        "Grpc-Metadata-Authorization": str(token)
    }

    response = requests.get(url, headers=headers)
    jsonObject = json.loads(response.text)
    profileID = jsonObject["result"][0]["id"]

    print(profileID)

    return profileID

def CreateGateway(token, data, profileID):

    url = "http://169.254.1.3:8080/api/gateways"

    data["gatewayProfileID"] = profileID
    data = json.dumps({"gateway":data})

    print(data)

    headers ={
        "Grpc-Metadata-Authorization": str(token)
    }

    response = requests.post(url, headers=headers, data=data)

    print(response.status_code)

    if (response.status_code != 200):
        return "Error"
    else:
        return "Success"

class AddEndnodeActivate(APIView):

    def post(self, request, devEui):

        requestData = request.data
        jsonObject = json.dumps(requestData)
        jsonObject = json.loads(jsonObject)
        token = GetTokenFromLoraAPI()

        createEndnodeActivateResponse = CreateEndnodeActivate(token, jsonObject, devEui)

        if (createEndnodeActivateResponse != "Error"):
            return Response(status=status.HTTP_201_CREATED)
        return Response(status=status.HTTP_400_BAD_REQUEST)

def CreateEndnodeActivate(token, data, deviceEui):
    
    url = "http://169.254.1.3:8080/api/devices/{}/activate".format(deviceEui)

    data = json.dumps({"deviceActivation":data})

    headers ={
        "Grpc-Metadata-Authorization": str(token)
    }

    response = requests.post(url, headers=headers, data=data)

    if (response.status_code != 200):
        return "Error"
    else:
        return "Success"
        
class UpdateEndnodeDetails(APIView):

    def post(self, request, eui):

        requestData = request.data
        jsonObject = json.dumps(requestData)
        jsonObject = json.loads(jsonObject)
        token = GetTokenFromLoraAPI()
        profileID = GetProfileID(token, "1")
        deviceEui = eui

        updateEndnodeDetailResponse = UpdateEndnode(token, jsonObject, profileID, deviceEui)

        if (updateEndnodeDetailResponse != "Error"):
            return Response(status=status.HTTP_201_CREATED)
        return Response(status=status.HTTP_400_BAD_REQUEST)

def UpdateEndnode(token, data, profileID, deviceEui):

    url = "http://169.254.1.3:8080/api/devices/{}".format(deviceEui)

    data["deviceProfileID"] = profileID
    data = json.dumps({"device":data})

    print(data)

    headers ={
        "Grpc-Metadata-Authorization": str(token),
        'Content-Type': 'application/json',
        'Accept': 'application/json'
    }

    response = requests.put(url, headers=headers, data=data)

    print(response.text)

    if (response.status_code != 200):
        return "Error"
    else:
        return "Success"

class DeleteEndnodeDetails(APIView):

    def post(self, request, eui):

        deviceEui = eui
        token = GetTokenFromLoraAPI()
        deleteEndnodeDetailResponse = DeleteEndnode(token, deviceEui)

        if (deleteEndnodeDetailResponse != "Error"):
            return Response(status=status.HTTP_200_OK)
        return Response(status=status.HTTP_400_BAD_REQUEST)

def DeleteEndnode(token, deviceEui):

    url = "http://169.254.1.3:8080/api/devices/{}".format(deviceEui)

    headers ={
        "Grpc-Metadata-Authorization": str(token)
    }

    response = requests.delete(url, headers=headers)

    if (response.status_code != 200):
        return "Error"
    else:
        return "Success"

class UpdateGatewayDetails(APIView):

    def post(self, request, eui):

        requestData = request.data
        jsonObject = json.dumps(requestData)
        jsonObject = json.loads(jsonObject)
        token = GetTokenFromLoraAPI()
        profileID = GetGatewayProfilID(token)
        deviceEui = eui

        updateGatewayDetailResponse = UpdateGateway(token, jsonObject, profileID, deviceEui)

        if (updateGatewayDetailResponse != "Error"):
            return Response(status=status.HTTP_201_CREATED)
        else:
            return Response(status=status.HTTP_400_BAD_REQUEST)

def UpdateGateway(token, data, profileID, deviceEui):

    url = "http://169.254.1.3:8080/api/gateways/{}".format(deviceEui)

    data["deviceProfileID"] = profileID
    data = json.dumps({"gateway":data})

    print(data)

    headers ={
        "Grpc-Metadata-Authorization": str(token)
    }

    response = requests.put(url, headers=headers, data=data)

    print(response.text)

    if (response.status_code != 200):
        return "Error"
    else:
        return "Success"

class DeleteGatewayDetails(APIView):

    def post(self, request, eui):

        gatewayEui = eui
        token = GetTokenFromLoraAPI()
        deleteGatewayDetailResponse = DeleteGateway(token, gatewayEui)

        if (deleteGatewayDetailResponse != "Error"):
            return Response(status=status.HTTP_200_OK)
        else:
            return Response(status=status.HTTP_400_BAD_REQUEST)

def DeleteGateway(token, gatewayEui):

    url = "http://169.254.1.3:8080/api/gateways/{}".format(gatewayEui)

    headers ={
        "Grpc-Metadata-Authorization": str(token)
    }

    response = requests.delete(url, headers=headers)

    if (response.status_code != 200):
        return "Error"
    else:
        return "Success"

class DeleteEndnodeActivationClass(APIView):

    def post(self, request, eui):
        
        print("Post function started!")
        
        deviceEui = eui
        token = GetTokenFromLoraAPI()
        deleteEndnodeActivationResponse = DeleteEndnodeActivation(token, deviceEui)

        if (deleteEndnodeActivationResponse != "Error"):
            return Response(status=status.HTTP_200_OK)
        else:
            return Response(status=status.HTTP_400_BAD_REQUEST)

def DeleteEndnodeActivation(token, deviceEui):

    print("Function started!")

    url = "http://169.254.1.3:8080/api/devices/{}/activation".format(deviceEui)

    headers ={
        "Grpc-Metadata-Authorization": str(token)
    }

    response = requests.delete(url, headers=headers)

    print(response.text)
    print(response)

    if (response.status_code != 200):
        return "Error"
    else:
        return "Success"

class GetAllGatewaysClass(APIView):

    def get(self, request):

        gateways = []

        url = "http://169.254.1.3:8080/api/gateways?limit=99999"

        token = GetTokenFromLoraAPI()

        headers ={
        "Grpc-Metadata-Authorization": str(token)
        }

        response = requests.get(url, headers=headers)

        jsonObject = json.loads(response.text)
        jsonObject = json.dumps(jsonObject)

        return HttpResponse(jsonObject, content_type='application/json; charset=UTF-8')

