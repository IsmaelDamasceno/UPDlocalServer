# UPDlocalServer
Programa para configurar um atalho de teclado do visual studio code, que ajuda a atualizar os arquivos para a pasta www

Use o atalho ctrl + shift + B apos configurar os arquivos

## Caso queria usar
O executável se encontra na pasta ./executavel/UPDlocalServer.exe

## Caso queira compilar o código:

O código se encontra na pasta ./codigo/UPDlocalServer.cpp

informações sobre a linguagem c++ utlizada, SO, e arquitetura computacional

c++ 20, windows x64

## Como funciona?

### Visual studio code: "tasks"
O atalho funciona por meio de uma ferramenta do visual studio chamada "tasks", uma task é uma tarefa executada pelo visual studio code. As tarefas
ficam localizadas em "{psta do seu projeto}/.vscode/tasks.json".

### A task em questão:
A task utilizada em questão é uma que executa um processo (programa), que por sua vez é um arquivo .bat que executa o comando robocopy, para copiar os arquivos contidos na pasta do seu projeto, para a pasta "c:/program files(x86)/easy php/www/{nome do projeto}/". Além disso, a task está setada como padrão, o atalho de teclado do visual studio code para executar a task padrão é CTRL + SHIFT + B
