from rest_framework import serializers
from .models import AddEndnode, EndnodeDetails, AddGateway

class AddEndnodeSerializer(serializers.ModelSerializer):

    class Meta:

        model = AddEndnode
        fields = '__all__'

class EndnodeDetailsSerializer(serializers.ModelSerializer):

    class Meta:

        model = EndnodeDetails
        fields = '__all__'

class AddGatewaySerializer(serializers.ModelSerializer):

    class Meta:

        model = AddGateway
        fields = '__all__'