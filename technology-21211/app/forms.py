from django import forms
from django.forms import ModelForm
from .models import Product
from django.core.exceptions import ValidationError


def description_validator(value):
    if len(value) <= 20:
        raise ValidationError("Product must have a good description")
    else:
        return value


def price_validator(value):
    if int(value) >= 1000:
        raise ValidationError("Product is too expensive")
    else:
        return value


class ProductForm(ModelForm):
    description = forms.CharField(validators=[description_validator])
    price = forms.DecimalField(validators=[price_validator])

    class Meta:
        model = Product
        fields = '__all__'
