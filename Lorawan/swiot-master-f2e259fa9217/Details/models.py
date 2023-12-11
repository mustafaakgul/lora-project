from django.db import models

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
