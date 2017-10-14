from rest_framework import serializers
from companies.models import Stock


class StockSerializer(serializers.ModelSerializer):

    class Meta:
        model = Stock
        fields = '__all__'

