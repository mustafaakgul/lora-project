# Generated by Django 3.0.1 on 2020-01-14 11:32

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('gateway', '0006_gateways_gatewaystatus'),
    ]

    operations = [
        migrations.AddField(
            model_name='gateways',
            name='gatewayLastSeen',
            field=models.TextField(null=True),
        ),
        migrations.AlterField(
            model_name='gateways',
            name='gatewayCreatedDate',
            field=models.TextField(null=True),
        ),
    ]
