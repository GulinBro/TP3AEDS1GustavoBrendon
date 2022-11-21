#include <iostream>
#include <windows.h>
#include <fstream>
#include "lista.hpp"
//Funções Para Inicializar A Lista.
void inicioM(MLista *lista){
    lista->inicio=NULL;
    lista->fim=NULL;
}

void inicioP(PLista *lista){
    lista->inicio=NULL;
    lista->fim=NULL;
}

void inicioF(FLista *lista){
    lista->inicio=NULL;
    lista->fim=NULL;
    lista->tamanho=0;
}

void inicioH(HLista *lista){
    lista->inicio=NULL;
}

void menu(){//Menu.
    system("cls");
    cout<<"|---------------------------|"<<endl;
    cout<<"|  HOSPITAL IFMG SJE        |"<<endl;
    cout<<"|---------------------------|"<<endl;
    cout<<"|1.Registro De Hospital     |"<<endl;
    cout<<"|2.Cadastro De Medicos      |"<<endl;
    cout<<"|3.Novo Atendimento/Triagem |"<<endl;
    cout<<"|4.Fila de Espera           |"<<endl;
    cout<<"|5.Lista de Medicos         |"<<endl;
    cout<<"|6.Saida                    |"<<endl;
    cout<<"|---------------------------|"<<endl<<endl;
}

void CadMedico(MLista *lista, int x){//Cadastro De Medicos.
    medico *novo;
    novo = new medico;

    if(x>5){
        cout<<"Número Limite de Medicos Alcançado!"<<endl;
        return;
    }
    cout<<"\n\t\t||CADASTRO DE MEDICOS||\n";
    cout<<"\nDigite O CRM:       ";
    cin>>novo->crm;
    cin.ignore();
    cout<<"Qual O Nome Do Medico:   ";
    gets(novo->nome);
    cout<<"Em Qual Area Este Medico Atua?:  ";
    gets(novo->area);
    novo->prox = NULL;

    if (lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->prox=novo;
        lista->fim=novo;
    }
    cout<<"|---------------------------------|"<<endl;
    cout<<"| Doutor Cadastrado Com Sucesso!! |"<<endl;
    cout<<"|---------------------------------|"<<endl;
    Sleep(1000);
    system("cls");
}

int triagem(){//Triagem Para Perguntas.

    char a;
    system("cls");
    cout<<"Confirme Os Sitomas Do Paciente A Seguir: "<<endl;
    cout<<"\nComprometimento da via aerea? s/n:  ";
    cin>>a;
    if(a=='s')
        return 0;
    cout<<"Respiracao ineficaz? s/n:  ";
    cin>>a;
    if(a=='s')
        return 0;
    cout<<"Choque? s/n:  ";
    cin>>a;
    if(a=='s')
        return 0;
    cout<<"Nao responde a etimulos? s/n:  ";
    cin>>a;
    if(a=='s')
        return 0;
    cout<<"Em convulsao? s/n:  ";
    cin>>a;
    if(a=='s')
        return 0;

    cout<<"Dor severa? s/n:  ";
    cin>>a;
    if(a=='s')
        return 1;
    cout<<"Grande hemorragia incontrolavel? s/n:  ";
    cin>>a;
    if(a=='s')
        return 1;
    cout<<"Alteracao do estado de conciencia? s/n:  ";
    cin>>a;
    if(a=='s')
        return 1;
    cout<<"Temperatura maior ou igual a 39 Graus C? s/n:  ";
    cin>>a;
    if(a=='s')
        return 1;
    cout<<"Trauma craniano severo? s/n:  ";
    cin>>a;
    if(a=='s')
        return 1;

    cout<<"Dor moderada? s/n:  ";
    cin>>a;
    if(a=='s')
        return 2;
    cout<<"Pequena hemorragia incontrolavel? s/n:  ";
    cin>>a;
    if(a=='s')
        return 2;
    cout<<"Vomito persistente? s/n:  ";
    cin>>a;
    if(a=='s')
        return 2;
    cout<<"Temperatura entre 38 Graus C e 39 Graus C? s/n:  ";
    cin>>a;
    if(a=='s')
        return 2;
    cout<<"Idoso ou gravida? s/n:  ";
    cin>>a;
    if(a=='s')
        return 2;

    cout<<"Dor leve? s/n:  ";
    cin>>a;
    if(a=='s')
        return 3;
    cout<<"Nauseas? s/n:  ";
    cin>>a;
    if(a=='s')
        return 3;
    cout<<"Temperatura entre 37 Graus C e 38 Graus C? s/n:  ";
    cin>>a;
    if(a=='s')
        return 3;

    return 4;
    
}

int CadPaciente(PLista *lista, int x){//Cadastro Do(s) Paciente(s).
    paciente *novo;
    novo = new paciente;

    cout<<"\n\t\t||CADASTRO DE PACIENTE||\n";
    cout<<"\nDigite a Idade:                      ";
    cin>>novo->idade;
    cout<<"Digite o CPF:                        ";
    cin>>novo->cpf;
    cin.ignore();
    cout<<"Qual O Nome Do Paciente:           ";
    gets(novo->nome);
    cout<<"Digite O Endereco:                   ";
    gets(novo->ende);
    cout<<"Digite O Seu Genero (M/F): ";
    cin>>novo->sexo;

    novo->caso=x;

    novo->prox = NULL;

    if (lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->prox=novo;
        lista->fim=novo;
    }
    cout<<"|----------------------|"<<endl;
    cout<<"| Paciente Cadastrado! |"<<endl;
    cout<<"|----------------------|"<<endl;
    Sleep(1000);
    system("cls");
    return novo->cpf;
}

void salvar(MLista *lista){//Salva Todos Os Dados Do Sistema.
    medico *aux;
    aux = lista->inicio;

    ofstream outFile;
    outFile.open("saida.txt", ios::out); //Abre O Arquivo Para Escrever.
    if (!outFile){ 
        cout<<" O Arquivo saida.txt Nao Pode Ser Aberto!!"<<endl;
        abort();
    }

    if(aux==NULL){
        cout<<"|-------------------------|"<<endl;
        cout<<"|Nenhum medico cadastrado!|"<<endl;
        cout<<"|-------------------------|\n"<<endl;
    }else{
        while(aux!= NULL){
            outFile<<aux->nome<<" "<<aux->area<<" "<<aux->crm<< "\n";
            aux = aux->prox;
        }
    }
    outFile.close();
    cout<<"|----------------------------|"<<endl;
    cout<<"| Dados Salvos Com Sucesso!! |"<<endl;
    cout<<"|----------------------------|"<<endl;
    Sleep(2000);
    system("cls");
}

int carregar(MLista *lista){//Carrega Dados Do Sistema.
    medico *novo;
    novo = new medico;
    novo->prox = NULL;
    int x=0;
    ifstream inFile;
    inFile.open("saida.txt", ios::in);
    if (!inFile){ 
        cout<<"Arquivo saida.txt Nao Pode Ser Aberto"<<endl;
        abort();
    }

    while(inFile>>novo->nome>>novo->area>>novo->crm){      
        if (lista->inicio == NULL){
            lista->inicio = novo;
            lista->fim = novo;
        }else{
            lista->fim->prox=novo;
            lista->fim=novo;
        }
        x++;
        novo = new medico;
        novo->prox = NULL;
    }
    cout<<"|--------------------------------------------|"<<endl;
    cout<<"| Dados Medicos Carregados Com Sucesso!!     |"<<endl;
    cout<<"|--------------------------------------------|"<<endl;
    return x;
}

void CadFila(FLista *lista, int caso, int x){//Armazena Na Fila O CPF E Um Numero De Prioridade.
    fila *novo, *aux, *anterior;
    novo = new fila;
    novo->prox = NULL;
    novo->item=caso;
    novo->cpf=x;
    aux = lista->inicio;

    if (lista->inicio==NULL){
        lista->inicio = novo;
        lista->fim = novo;
        lista->tamanho=1;
    }else{
        anterior=aux;
        lista->tamanho++;
        while(aux!=NULL){
            if(novo->item<aux->item){
                if(aux==lista->inicio){
                    novo->prox=lista->inicio;
                    lista->inicio=novo;
                }else{
                    novo->prox=anterior->prox;
                    anterior->prox=novo;
                system("pause");
                }
                break;
            }
            if(aux==lista->fim){
                aux->prox=novo;
                lista->fim=novo;
                novo->prox = NULL;
            }
            anterior=aux;
            aux=aux->prox;
        }
    }
    cout<<"|-------------------------|"<<endl;
    cout<<"|  Paciente Cadastrado!!  |"<<endl;
    cout<<"|-------------------------|"<<endl;
    Sleep(1000);
    system("cls");
}

int atendido(FLista *lista){//Atualiza o Inicio Da Fila, Apos O Atendimento.
    fila *aux;
    int x;
    aux = lista->inicio;

    if(lista->inicio==NULL){
        cout<<"|-------------------------------|"<<endl;
        cout<<"|  Sem Pacientes Para Atender!! |";
        cout<<"|-------------------------------|\n"<<endl;
        return 10;
    }else{
        cout<<"Paciente Do CPF "<<aux->cpf<<" Entrou Em Atendimento!!"<<endl;
        x=aux->item;
        lista->inicio = lista->inicio->prox;
        free(aux);
        lista->tamanho--;
    }
    return x;
}

int atualiza(HLista *lista, int x){//Atualiza Geral As Informaçoes Do Hospital De Acordo Com int x.
    hospital *aux;//Essa Lista Sempre Se Mantem Atualizada, Dos Numeros De Pacientes E Medicos.
    aux=lista->inicio;

    if(x==1){
        if(aux->nummedico<5){
            aux->nummedico++;
            aux->medico++;
            return aux->nummedico;
        }else{
            return 6;
        }
    }
    if(x==2){
        aux->paciente++;
    }
    if(x==5){
        if(aux->paciente>0){
            return 1;
        }
    }
    if(x==3){
        if(aux->medico>0 && aux->paciente>0){
            aux->medico--;
            aux->paciente--;
            return 1;
        }else{
            return 0;
        }
    }
    if(x==4){
        aux->atendidos++;
        aux->medico++;
    }

    return 0;
}

void mostraM(MLista *lista){//Função Para Visualizar Os Medicos.
    medico *aux;
    aux = lista->inicio;

    if(aux==NULL){
        cout<<"|-----------------------------|"<<endl;
        cout<<"|  Nenhum Medico Cadastrado!! |"<<endl;
        cout<<"|-----------------------------|\n"<<endl;
    }else{
        while(aux!= NULL){
            cout<<"Nome: "<<aux->nome<<endl;
            cout<<"Area: "<<aux->area<<endl;
            cout<<"CRM:  "<<aux->crm<<endl<<endl;
            aux = aux->prox;
        }
        
    }
        system("pause");
        system("cls");
}

void mostraF(FLista *lista){//Mostra Fila Para Atendimento.
    fila *aux;
    aux = lista->inicio;

    if(aux==NULL){
        cout<<"|----------------------------------|"<<endl;
        cout<<"|  Nenhum Paciente Para Atender !! |"<<endl;
        cout<<"|----------------------------------|\n"<<endl;
    }else{
        while(aux!= NULL){
            cout<<"Item: "<<aux->item<<endl;
            aux = aux->prox;
        }  
    }
    system("pause");
    system("cls");
    
}

void mostraH(HLista *lista){//Mostra Os Dados Hospitalares.
    hospital *aux;
    aux=lista->inicio;

    system("cls");
    cout<<"\nTotal De Medicos:    "<<aux->nummedico;
    cout<<"\nMedicos Disponiveis: "<<aux->medico;
    cout<<"\nTotal De Pacientes:  "<<aux->paciente;
    cout<<"\nPacientes Atendidos: "<<aux->atendidos<<"\n";
    system("pause");
}

void prioridade(int caso){//Para Retorna A Prioridade.
    system("cls");
    if(caso==0){
        cout<<"Nivel VERMELHO: ATENDIMENTO IMEDIATO!!!!";
    }else{
        if(caso==1){
            cout<<"Nivel Laranja: Atendimento Em Ate 10 Minutos";
        }else{
            if(caso==2){
                cout<<"Nivel Amarelo: Atendimento Em Ate 60 Minutos";
            }else{
                if(caso==3){
                    cout<<"Nivel Verde: Atendimento Em Ate 120 Minutos";
                }else{
                    cout<<"Nivel Azul: Atendimento Em Ate 240 Minutos";
                }
            }
        }
    }
    Sleep(2000);
    system("cls");
}

int segundo(int x){//Retorna O Tempo De Atendiemnto De Acordo Com O Nivel De Prioridade
    if(x==0){
        return 40;
    }else{
        if(x==1){
            return 30;
        }else{
            if(x==2){
                return 20;
            }else{
                if(x==3){
                    return 10;
                }else{
                    return 5;
                }
            }
        }
    }
}

void salvarhospital(HLista *lista){//Salva Os Dados Do Hospital.
    hospital *aux;
    aux = lista->inicio;

    ofstream outFile;
    outFile.open("hospital.txt", ios::out); //Abre o Arquivo Para Escrever.
    if (!outFile){ 
        cout<<"Arquivo saida.txt Nao Pode Ser Aberto"<<endl;
        abort();
    }

    if(aux==NULL){
        cout<<"|----------------------------|"<<endl;
        cout<<"|  Nenhum Dado Encontrado !! |"<<endl;
        cout<<"|----------------------------|\n"<<endl;
    }else{
        while(aux!= NULL){
            outFile<<aux->atendidos<<" "<<aux->medico<<" "<<aux->nummedico<<" "<<aux->paciente<< "\n";
            aux=aux->prox;
        }
    }
    outFile.close();
    cout<<"|----------------------------|"<<endl;
    cout<<"| Dados Salvos Com Sucesso!! |"<<endl;
    cout<<"|----------------------------|"<<endl;
    Sleep(2000);
    system("cls");
}

void carregarhospital(HLista *lista){//Carrega Os Dados Do Hospital.
    hospital *novo;
    novo = new hospital;
    novo->prox = NULL;

    ifstream inFile;
    inFile.open("hospital.txt", ios::in);
    if (!inFile){ 
        cout<<"Arquivo saida.txt Nao Pode Ser Aberto"<<endl;
        abort();
    }

    while(inFile>> novo->atendidos >>novo->medico>>novo->nummedico>>novo->paciente){      
        if (lista->inicio==NULL){
            lista->inicio=novo;   
        }
        novo = new hospital;
        novo->prox = NULL;
    }
    cout<<"|--------------------------------------------|"<<endl;
    cout<<"| Dados Do Hospital Carregados Com Sucesso!! |"<<endl;
    cout<<"|--------------------------------------------|"<<endl;
}

