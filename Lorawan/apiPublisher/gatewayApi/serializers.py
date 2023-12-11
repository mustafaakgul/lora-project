from rest_framework import serializers
from .models import  AddGateway

class AddGatewaySerializer(serializers.ModelSerializer):

    class Meta:

        model = AddGateway
        fields = '__all__'