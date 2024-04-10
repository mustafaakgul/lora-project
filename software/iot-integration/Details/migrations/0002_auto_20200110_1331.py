# Generated by Django 3.0.2 on 2020-01-10 10:31

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('Details', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='AddEndnode',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('applicationID', models.TextField(verbose_name='App ID')),
                ('description', models.TextField()),
                ('devEUI', models.TextField()),
                ('deviceProfileID', models.TextField()),
                ('name', models.TextField()),
                ('referanceAltitude', models.IntegerField(default=0)),
                ('skipFCntCheck', models.BooleanField(default=True)),
            ],
        ),
        migrations.CreateModel(
            name='AddGateway',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('description', models.TextField()),
                ('discoveryEnabled', models.TextField(default='true')),
                ('gatewayProfileID', models.TextField()),
                ('gatewayEui', models.TextField()),
                ('accurary', models.IntegerField(default=0)),
                ('altitude', models.IntegerField(default=0)),
                ('latitude', models.IntegerField(default=0)),
                ('longitude', models.IntegerField(default=0)),
                ('gatewayName', models.TextField()),
                ('networkServerID', models.TextField()),
                ('organizationID', models.TextField()),
            ],
        ),
        migrations.RenameField(
            model_name='endnodedetails',
            old_name='devEUI',
            new_name='deviceEUI',
        ),
        migrations.RenameField(
            model_name='endnodedetails',
            old_name='deviceProfileID',
            new_name='deviceProfilID',
        ),
        migrations.RemoveField(
            model_name='endnodedetails',
            name='referanceAltitude',
        ),
        migrations.RemoveField(
            model_name='endnodedetails',
            name='skipFCntCheck',
        ),
        migrations.AddField(
            model_name='endnodedetails',
            name='lastSeenAt',
            field=models.TextField(default='Never'),
        ),
        migrations.AddField(
            model_name='endnodedetails',
            name='location',
            field=models.TextField(default='Unknown'),
        ),
        migrations.AlterField(
            model_name='endnodedetails',
            name='applicationID',
            field=models.TextField(),
        ),
    ]