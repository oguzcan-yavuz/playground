from django.shortcuts import get_object_or_404
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from companies.models import Stock
from companies.serializers import StockSerializer


# list all stocks or create a new one
class StockList(APIView):

    def get(self, request):
        stock = Stock.objects.all()
        serializer = StockSerializer(stock, many=True)
        return Response(serializer.data)

    def post(self):
        pass

