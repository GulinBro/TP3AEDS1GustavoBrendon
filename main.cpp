#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <windows.h>
#include "lista.hpp"
#include "funcoes.cpp"

using namespace std;

int main(){
    int opcao, caso, cpf, x, ajuda, m1=0, i, m2=0, m3=0, m4=0, m5, vdd1, vdd2, vdd3, vdd4, vdd5;
    char aguardando;
    int tempo[5];
    int nivel[5];
    //Cria A Listra Do Tipo.
    MLista L1;
    PLista P1;
    FLista F1;
    HLista H1;
    //Funções Para Inicio.
    inicioM(&L1);
    inicioP(&P1);
    inicioF(&F1);
    inicioH(&H1);
    
    
    // Dados(&H1);
    carregar(&L1);
    carregarhospital(&H1);
    Sleep(2000);
    
    for(;;){//Mantem Infinito Ate A Quebra Do Loop.
        menu();
        cout<<"Insira a opcao: ";
        cin>>opcao;
        switch (opcao){//Menu Para Guia De Acordo Com A Opção.

        case 1:
            mostraH(&H1);
        break;

        case 2:
            ajuda=atualiza(&H1, 1);//Verifica Se O Numero De Medicos Atingiu 5, Que E O Limite.
            CadMedico(&L1, ajuda);//Cadastra Medico Se Tive Vaga.
        break;

        case 3://Cadastro De Paciente.
            inicio:
            caso=triagem();//Chama A Pergunta.
            prioridade(caso);
            cpf=CadPaciente(&P1, caso);//Cadastra Paciente.
            atualiza(&H1, 2);//Atualiza A Lista Dizendo Que Tem Paciente.
            CadFila(&F1, caso, cpf);//Cadastra Na Fila De Atendimento O Cliente.
            cout<<"A paciente aguardando triagem:(s/n)  :";
            cin>>aguardando;
            if(aguardando=='s'){//Se Quiser Cadastra Novo Paciente.
                goto inicio;
            }      

            x=atualiza(&H1, 5);//Verifica Se Tem Paciente Para Atender.
            while(x==1){
                //Variavel Para Calcular tempo De Atendimento.
                time_t t1 = time(NULL);
                time_t t2 = time(NULL);
                time_t t3 = time(NULL);
                time_t t4 = time(NULL);
                time_t t5 = time(NULL);
                tem:
                if(m1==0){//Atende Um Paciente.
                    ajuda=atualiza(&H1, 3);//Diminui Um Medico E Paciente.
                    if(ajuda==1){//Se Tiver Medico E Paciente, Ele Começa A Atender, Se Nao Passa A Ignorar A Função.
                        nivel[0]=atendido(&F1);
                        tempo[0]=segundo(nivel[0]);
                        vdd1=0;
                    }else{
                        vdd1=1;
                    }
                    m1=1;
                }else{
                    if(vdd1==0){
                        time_t t11 = time(NULL);
                        if(difftime(t11, t1)<tempo[0]){//Compara O Tempo, Se Tive Passado O Tempo De Atendimento.
                        }else{
                            cout<<"Paciente atendido!"<<endl;//Vem Para Ca, E Começa A Verificar De Novo.
                            atualiza(&H1, 4);
                            m1=0;
                            vdd1=1;
                            time_t t1 = time(NULL);
                            goto tem;
                        }
                    }
                }

                if(m2==0){
                    ajuda=atualiza(&H1, 3);//Diminui Um Medico E Paciente.
                    if(ajuda==1){
                        nivel[1]=atendido(&F1);
                        tempo[1]=segundo(nivel[1]);
                        vdd2=0;
                    }else{
                        vdd2=1;
                    }
                    m2=1;
                }else{
                    if(vdd2==0){
                        time_t t22 = time(NULL);
                        if(difftime(t22, t2)<tempo[1]){
                        }else{
                            cout<<"Paciente atendido!"<<endl;
                            atualiza(&H1, 4);
                            m2=0;
                            vdd2=1;
                            time_t t2 = time(NULL);
                            goto tem;
                        }
                    }
                }

                 if(m3==0){
                    ajuda=atualiza(&H1, 3);//Diminui Um Medico E Paciente.
                    if(ajuda==1){
                        nivel[2]=atendido(&F1);
                        tempo[2]=segundo(nivel[2]);
                        vdd3=0;
                    }else{
                        vdd3=1;
                    }
                    m3=1;
                }else{
                    if(vdd3==0){
                        time_t t33 = time(NULL);
                        if(difftime(t33, t3)<tempo[2]){
                        }else{
                            cout<<"Paciente atendido!"<<endl;
                            atualiza(&H1, 4);
                            m3=0;
                            vdd3=1;
                            time_t t3 = time(NULL);
                            goto tem;
                        }
                    }
                }

                 if(m4==0){
                    ajuda=atualiza(&H1, 3);//Diminui Um Medico E Paciente.
                    if(ajuda==1){
                        nivel[3]=atendido(&F1);
                        tempo[3]=segundo(nivel[3]);
                        vdd4=0;
                    }else{
                        vdd4=1;
                    }
                    m4=1;
                }else{
                    if(vdd4==0){
                        time_t t44 = time(NULL);
                        if(difftime(t44, t4)<tempo[3]){
                        }else{
                            cout<<"Paciente atendido!"<<endl;
                            atualiza(&H1, 4);
                            m4=0;
                            vdd4=1;
                            time_t t4 = time(NULL);
                            goto tem;
                        }
                    }
                }

                 if(m5==0){
                    ajuda=atualiza(&H1, 3);//Diminui Um Medico E Paciente.
                    if(ajuda==1){
                        nivel[4]=atendido(&F1);
                        tempo[4]=segundo(nivel[4]);
                        vdd5=0;
                    }else{
                        vdd5=1;
                    }
                    m5=1;
                }else{
                    if(vdd5==0){
                        time_t t55 = time(NULL);
                        if(difftime(t55, t5)<tempo[4]){
                        }else{
                            cout<<"Paciente atendido!"<<endl;
                            atualiza(&H1, 4);
                            m5=0;
                            vdd5=1;
                            time_t t5 = time(NULL);
                            goto tem;
                        }
                    }
                }

                if(vdd1==0 || vdd2==0 || vdd3==0 || vdd4==0 || vdd5==0){//Caso Tenha Alguem Em Atendimento, Fica No Loop Ate Terminar O Atendimento.
                    goto tem;
                }
                x=atualiza(&H1, 5);//Atualiza O x, Para Ter A Certeza De Atender Todos.
            }
            
            m1=0; m2=0; m3=0; m4=0; m5=0;
            cout<<"Todos os pacientes foram atendidos"<<endl;
            system("pause");
        break;

        case 4:
            mostraF(&F1);//Mostra Fila De Atendimento.
        break;

        case 5:
            mostraM(&L1); //Mostra Medicos. 
        break;

        case 6:
            salvar(&L1);  //Salva Dados.
            salvarhospital(&H1);
            exit(0); //Sair.  
        break;
        }
    }
    return 0;
}
