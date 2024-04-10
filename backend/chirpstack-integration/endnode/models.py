from django.db import models

class Endnode(models.Model):

    timestamp = models.DateTimeField(auto_now_add=True, null=True)
    data = models.CharField(verbose_name="Datas", max_length=200)
    rssiData = models.CharField(verbose_name="RSSI Data", max_length=200, null=True, blank=True)
    snrData = models.CharField(verbose_name="SNR Data", max_length=200, null=True, blank=True)
    #latitude = models.CharField(verbose_name="Latitude", max_length=200)
    #longitude = models.CharField(verbose_name="Longitude", max_length=200)
    #altitude = models.CharField(verbose_name="Altitude", max_length=200)

    def __str__(self):
        return self.data

class AddEndnode(models.Model):

    applicationID = models.TextField(verbose_name="App ID")
    description = models.TextField()
    devEUI = models.TextField()
    deviceProfileID = models.TextField()
    name = models.TextField()
    referanceAltitude = models.IntegerField(default=0)
    skipFCntCheck = models.BooleanField(default=True)

    def __str__(self):
        return self.name

class EndnodeDetails(models.Model):

    deviceEUI = models.TextField()
    name = models.TextField()
    applicationID = models.TextField()
    description = models.TextField()
    deviceProfilID = models.TextField()
    lastSeenAt = models.TextField(default="Never")
    location = models.TextField(default="Unknown")

    def __str__(self):
        return self.name
