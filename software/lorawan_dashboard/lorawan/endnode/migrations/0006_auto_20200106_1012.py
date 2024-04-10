# Generated by Django 3.0.1 on 2020-01-06 07:12

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('endnode', '0005_auto_20200103_1259'),
    ]

    operations = [
        migrations.AddField(
            model_name='endnode',
            name='last_value',
            field=models.CharField(max_length=50, null=True),
        ),
        migrations.AlterField(
            model_name='endnode',
            name='activation_method',
            field=models.CharField(blank=True, default='ABP', max_length=50, null=True),
        ),
        migrations.AlterField(
            model_name='endnode',
            name='device_type',
            field=models.CharField(max_length=50, null=True),
        ),
    ]