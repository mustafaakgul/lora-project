from django.shortcuts import render,HttpResponse,redirect,get_object_or_404,reverse
from .forms import EndnodeForm
from django.contrib import messages
from .models import Endnode
from django.contrib.auth.decorators import login_required

#@login_required(login_url = "user:login")
def EndNodes(request):
    endnodes = Endnode.objects.all()
    context = {
        "endnodes" : endnodes
    }
    return render(request, "end_node_index.html", context)

#@login_required(login_url = "user:login")
def AddEndNode(request):
    form = EndnodeForm(request.POST or None)
    if form.is_valid():
        endnode = form.save(commit=False)
        endnode.author = request.user

        activationMethodabp = request.POST.get("abp", False)
        activationMethodotaa = request.POST.get("otaa", False)
        if (activationMethodabp == "abp" and activationMethodotaa == False):
            activationmethod = "ABP"
        if (activationMethodotaa == "otaa" and activationMethodabp == False):
            activationmethod = "OTAA"
        if (activationMethodabp == False and activationMethodotaa == False):
            activationmethod = "ABP"
        endnode.activation_method = activationmethod

        devicetypetemp = request.POST.get("temphum", False)
        devicetypeenergy = request.POST.get("energy", False)
        devicetypewater = request.POST.get("water", False)
        if (devicetypetemp == "temphum" and devicetypeenergy == False and devicetypewater ==False):
            devicetype = "Temperature-Humidity"
        if (devicetypeenergy == "energy" and devicetypetemp == False and devicetypewater ==False):
            devicetype = "Energy"
        if (devicetypewater == "water" and devicetypetemp == False and devicetypeenergy ==False):
            devicetype = "Water"
        endnode.device_type = devicetype

        endnode.status = "Connected"

        endnode.save()
        messages.success(request, "Article added successfully")
        #activationmethodlist = ["ABP", "OTAA"]
        #return redirect("article:dashboard")
    #return render(request, "end_node_add.html", {"activationmethodlist" : {"ABP", "OTAA"}})
    #return render(request, "end_node_add.html", {"form" : form})
    
def EditEndnode(request, id):
    endnode = Endnode.objects.get(id = id)

    context = {
        "endnode": endnode
    }

    if (request.method == "POST"):

        endnode = Endnode.objects.get(id = id)

        endnode.author = request.user
        activationMethodabp = request.POST.get("abp", False)
        activationMethodotaa = request.POST.get("otaa", False)
        if (activationMethodabp == "abp" and activationMethodotaa == False):
            activationmethod = "ABP"
        if (activationMethodotaa == "otaa" and activationMethodabp == False):
            activationmethod = "OTAA"
        if (activationMethodabp == False and activationMethodotaa == False):
            activationmethod = "ABP"
        endnode.activation_method = activationmethod
        devicetypetemp = request.POST.get("temphum", False)
        devicetypeenergy = request.POST.get("energy", False)
        devicetypewater = request.POST.get("water", False)
        if (devicetypetemp == "temphum" and devicetypeenergy == False and devicetypewater == False):
            devicetype = "Temperature-Humidity"
        if (devicetypeenergy == "energy" and devicetypetemp == False and devicetypewater == False):
            devicetype = "Energy"
        if (devicetypewater == "water" and devicetypetemp == False and devicetypeenergy == False):
            devicetype = "Water"
        endnode.device_type = devicetype
        endnode.status = "Connected"

        endnode.save()
        return redirect("/endnode/")
    return render(request, "edit_endnode.html", context=context)