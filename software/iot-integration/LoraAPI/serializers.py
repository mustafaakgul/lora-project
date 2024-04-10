from rest_framework import serializers
from .models import Endnode

class EndnodeSerializer(serializers.ModelSerializer):

    class Meta:

        model = Endnode
        fields = '__all__'