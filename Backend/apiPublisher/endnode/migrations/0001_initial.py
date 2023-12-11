# Generated by Django 3.0.2 on 2020-01-22 10:31

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Endnode',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('timestamp', models.DateTimeField(auto_now_add=True, null=True)),
                ('data', models.CharField(max_length=200, verbose_name='Datas')),
                ('rssiData', models.CharField(max_length=200, verbose_name='RSSI Data')),
                ('snrData', models.CharField(max_length=200, verbose_name='SNR Data')),
                ('latitude', models.CharField(max_length=200, verbose_name='Latitude')),
                ('longitude', models.CharField(max_length=200, verbose_name='Longitude')),
                ('altitude', models.CharField(max_length=200, verbose_name='Altitude')),
            ],
        ),
    ]
