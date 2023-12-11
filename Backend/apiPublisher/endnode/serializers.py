from rest_framework import serializers
from .models import Endnode,AddEndnode,EndnodeDetails

class EndnodeSerializer(serializers.ModelSerializer):

    class Meta:

        model = Endnode
        fields = '__all__'

class AddEndnodeSerializer(serializers.ModelSerializer):

    class Meta:

        model = AddEndnode
        fields = '__all__'

class EndnodeDetailsSerializer(serializers.ModelSerializer):

    class Meta:

        model = EndnodeDetails
        fields = '__all__'
