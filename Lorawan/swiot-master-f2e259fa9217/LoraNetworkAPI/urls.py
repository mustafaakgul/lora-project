from django.contrib import admin
from django.urls import path
from django.conf.urls import url
from rest_framework.urlpatterns import format_suffix_patterns
from LoraAPI import views as Datas
from Details import views as Details
from rest_framework.authtoken import views as Token

urlpatterns = [
    path('admin/', admin.site.urls),
    path("endnodes/", Datas.EndnodeDatas.as_view()),
    path("endnodes/add/", Details.AddEndnode.as_view()),
    path("endnodes/update/<str:eui>/", Details.UpdateEndnodeDetails.as_view()),
    path("gateways/update/<str:eui>/", Details.UpdateGatewayDetails.as_view()),
    path("endnodes/delete/<str:eui>/", Details.DeleteEndnodeDetails.as_view()),
    path("gateways/delete/<str:eui>/", Details.DeleteGatewayDetails.as_view()),
    path("endnodes/delete/activation/<str:eui>/", Details.DeleteEndnodeActivationClass.as_view()),
    path("endnodes/add/activation/<str:devEui>/", Details.AddEndnodeActivate.as_view()),
    path("gateways/add/", Details.AddGateway.as_view()),
    path("gateways/all/", Details.GetAllGatewaysClass.as_view()),
    path("endnodes/details/<str:eui>/", Details.GetEndnodeDetails.as_view()),
    path("endnodes/activation/<str:eui>/", Details.GetEndnodeActivation.as_view()),
    path("gateways/details/<str:eui>/", Details.GetGatewayDetails.as_view()),
    path("api-token-auth/", Token.obtain_auth_token, name="api-token-auth")
]

urlpatterns = format_suffix_patterns(urlpatterns)
