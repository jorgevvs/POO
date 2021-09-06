#include <iostream>
using std::cout;
using std::endl;
using std::string;

#include "Agenda.h"
#include "Pessoa.h"

Agenda::Agenda(int tamanhodaAgenda){
    this->tamanhoAgenda = tamanhodaAgenda;
    this->quantidadeContatos = 0;
    this->agenda = new Pessoa *[tamanhodaAgenda];
}

Agenda::~Agenda(){
    for (int i = 0; i < this->quantidadeContatos; i++){
        delete agenda[i];
    }
    delete[] agenda;
}

void Agenda::adicionaContato(Pessoa *pessoa){
    if (this->tamanhoAgenda > this->quantidadeContatos){
        this->agenda[quantidadeContatos] = pessoa;
        this->quantidadeContatos++;
    }
}

void Agenda::buscaContato(string busca){
    for (int i = 0; i < this->quantidadeContatos; i++){
        if (busca == agenda[i]->getNome() || busca == agenda[i]->getCpforCNPJ()){
        agenda[i]->exibirPessoa();
        return;
        }
    }
        cout << "Pessoa não encontrada!" << endl;
}

void Agenda::removeContato(string busca){
    for (int i = 0; i < this->quantidadeContatos; i++){
        if (busca == agenda[i]->getNome()) pos = i;
        else if (busca == agenda[i]->getCpforCNPJ()) pos = i;
    }

    delete agenda[pos];

    for (int i = this->pos + 1; i < this->quantidadeContatos; i++){
        agenda[i - 1] = agenda[i];
    }

    quantidadeContatos--;
}

void Agenda::printAgenda() const{
    cout << "\n=============== Agenda ===============" << endl;
    for(int i = 0; i < quantidadeContatos; i++){
        agenda[i]->exibirPessoa();
    }
    cout << "======================================\n" << endl;
}