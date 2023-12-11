"""apiPublisher URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from django.conf.urls import url
from rest_framework.urlpatterns import format_suffix_patterns
from endnode import views as Datas
from gatewayApi import views as Details
from rest_framework.authtoken import views as Token

urlpatterns = [
    # path("api-token-auth/", Token.obtain_auth_token, name="api-token-auth"),
    path('admin/', admin.site.urls),
    path("endnodes/", Datas.EndnodeDatas.as_view()),

    path("endnodes/add/", Datas.AddEndnode.as_view()),
    path("endnodes/details/<str:eui>/", Datas.GetEndnodeDetails.as_view()),
    path("endnodes/update/<str:eui>/", Datas.UpdateEndnodeDetails.as_view()),
    path("endnodes/delete/<str:eui>/", Datas.DeleteEndnodeDetails.as_view()),
    path("endnodes/add/activation/<str:devEui>/", Datas.AddEndnodeActivate.as_view()),
    path("endnodes/activation/<str:eui>/", Datas.GetEndnodeActivation.as_view()),
    path("endnodes/delete/activation/<str:eui>/", Datas.DeleteEndnodeActivationClass.as_view()),

    path("gateways/all/", Details.GetAllGatewaysClass.as_view()),
    path("gateways/add/", Details.AddGateway.as_view()),
    path("gateways/details/<str:eui>/", Details.GetGatewayDetails.as_view()),
    path("gateways/update/<str:eui>/", Details.UpdateGatewayDetails.as_view()),
    path("gateways/delete/<str:eui>/", Details.DeleteGatewayDetails.as_view()),

]

urlpatterns = format_suffix_patterns(urlpatterns)

