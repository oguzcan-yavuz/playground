from django.db import models


class Stock(models.Model):
    ticker = models.CharField(max_length=10)
    price_open = models.FloatField()
    price_close = models.FloatField()
    volume = models.IntegerField()

    def __str__(self):
        return self.ticker
