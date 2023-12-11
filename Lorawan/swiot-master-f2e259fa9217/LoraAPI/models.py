from django.db import models

class Endnode(models.Model):

    timestamp = models.DateTimeField(auto_now_add=True, null=True)
    data = models.CharField(verbose_name="Datas", max_length=200)
    rssiData = models.CharField(verbose_name="RSSI Data", max_length=200)
    snrData = models.CharField(verbose_name="SNR Data", max_length=200)
    latitude = models.CharField(verbose_name="Latitude", max_length=200)
    longitude = models.CharField(verbose_name="Longitude", max_length=200)
    altitude = models.CharField(verbose_name="Altitude", max_length=200)

    def __str__(self):
        return self.data
