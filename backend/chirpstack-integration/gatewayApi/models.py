from django.db import models

class Gateway(models.Model):

    timestamp = models.DateTimeField(auto_now_add=True, null=True)
    data = models.CharField(verbose_name="Datas", max_length=200)
    rssiData = models.CharField(verbose_name="RSSI Data", max_length=200, null=True, blank=True)
    snrData = models.CharField(verbose_name="SNR Data", max_length=200, null=True, blank=True)
    #latitude = models.CharField(verbose_name="Latitude", max_length=200)
    #longitude = models.CharField(verbose_name="Longitude", max_length=200)
    #altitude = models.CharField(verbose_name="Altitude", max_length=200)

    def __str__(self):
        return self.data

class AddGateway(models.Model):

    description = models.TextField()
    discoveryEnabled = models.TextField(default="true")
    gatewayProfileID = models.TextField()
    gatewayEui = models.TextField(null=True)
    accurary = models.IntegerField(default=0)
    altitude = models.IntegerField(default=0)
    latitude = models.IntegerField(default=0)
    longitude = models.IntegerField(default=0)
    gatewayName = models.TextField(null=True)
    networkServerID = models.TextField()
    organizationID = models.TextField()

    def __str__(self):
        return self.gatewayName
