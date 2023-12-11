from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from .models import Endnode
from .serializers import EndnodeSerializer

class EndnodeDatas(APIView):

    def get(self, request):

        endnodes = Endnode.objects.all()
        serializer = EndnodeSerializer(endnodes, many=True)
        return Response(serializer.data)

    def post(self, request):
        serializer = EndnodeSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


