from django.contrib import admin
from django.urls import path
from . import views
from django.conf import settings
from django.conf.urls.static import static

app_name = "endnode"

urlpatterns = [
    path('', views.EndNodes, name="endnodes"),
    path('addendnode/', views.AddEndNode, name="addendnode"),
    path("state/<int:id>/", views.EditEndnode, name="editendnode")
]