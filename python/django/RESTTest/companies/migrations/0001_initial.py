# -*- coding: utf-8 -*-
# Generated by Django 1.11.4 on 2017-08-10 13:58
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Stock',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('ticker', models.CharField(max_length=10)),
                ('price_open', models.FloatField()),
                ('price_close', models.FloatField()),
                ('volume', models.IntegerField()),
            ],
        ),
    ]
