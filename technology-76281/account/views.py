from django.contrib.auth.decorators import login_required
from django.shortcuts import redirect, render

from django.contrib.auth import (
    get_user_model,
    authenticate,
    login,
    logout
)
  
from .models import (
    Account,
    Team
)

from .forms import (
    SignUpForm,
    LoginForm,
    TeamForm
)

def home(request):
    context = dict()
    context['team'] = None
    if request.method == 'GET':
        try:
            user_obj = Account.objects.get(username=request.user.username)
        except:
            user_obj = None
        if user_obj and user_obj.team:
            context['team'] = user_obj.team.name

    return render(request, 'home.html', context=context)


def signup(request):
    context = {}
    if request.method == 'POST':
        form = SignUpForm(request.POST)
        if form.is_valid():
            form.save()
            username = form.cleaned_data.get('username')
            password = form.cleaned_data.get('password1')
            user = authenticate(username=username, password=password)
            login(request, user)
            return redirect('team')
    else:
        form = SignUpForm()
    context['form'] = form
    return render(request, 'signup.html', context=context)


def login_account(request):
    context = {}
    if request.method == 'POST':
        form = LoginForm(request.POST)
        if form.is_valid():
            username = form.cleaned_data['username']
            password = form.cleaned_data['password']
            user = authenticate(
                username=username,
                password=password
            )
            if user is not None:
                login(request, user)
                return redirect('home')
            else:
                return redirect('login')
        else:
            return redirect('login')
    else:
        form = LoginForm()
    context = {
        'form':form
    }

    return render(request, 'login.html', context)


def logout_account(request):
    if redirect.method == 'GET':
        logout(request)
        return redirect('login')
    return render(request, 'home.hrml')


@login_required
def joinoradd_team(request):
    context = {}
    if request.method == 'POST':
        form = TeamForm(request.POST)
        if form.is_valid():
            team_name = form.cleaned_data['name']
            team, created = Team.objects.get_or_create(
                name=team_name
            )

            if created:
                team.jitsi_url_path = f'http://meet.jit.si/{team_name}'
                team.save()
            account = Account.objects.get(
                username=request.user.username
            )
            account.team = team
            account.save()
            return redirect('home')
        else:
            return redirect('team')
    else:
        form = TeamForm()
        context['form'] = form
        account = Account.objects.filter(
            username=request.user.username
        ).first()
        if account and account.team:
            return redirect('home')
    return render(request, 'team.html', context=context)


def exit_team(request):
    if request.method == 'GET':
        account_obj = Account.objects.filter(username=request.user.username).first()
        print(account_obj.team)
        if account_obj and account_obj.team:
            account_obj.team = None
            account_obj.save()
            return redirect('home')
    return redirect('home')
