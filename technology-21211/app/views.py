from django.http import JsonResponse
from django.shortcuts import get_object_or_404
from app.models import OrderItem, Order


def checkout(request, order_pk):
    order = get_object_or_404(Order, pk=order_pk)
    orders = OrderItem.objects.filter(order_id__exact=order_pk)
    prices = [(order.product.price*order.quantity) for order in orders]
    price = sum(prices)
    return JsonResponse({"total_price": "{:.2f}".format(price)})
