#include "deck.h"

Deck* createDeck () {
  return NULL;
}

/*Função que retorna a coordenada armazenada na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getFront (Deck *d) {
   return d->p;
}

/*Função que retorna a coordenada armazenada na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getRear (Deck *d) {
   Deck *aux = d;
   
   while (aux->next != NULL){
      aux = aux->next;
   }

   return aux->p;
}

/*Função para inserir na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertFront (Deck *d, Point p, char field[][SIZE]) {
   
    Deck *novo = (Deck*)malloc(sizeof(Deck));
    novo->p = p;
   
    if(d!= NULL){
        d->prev = novo;
        novo->next = d;
        field[p.x][p.y] = '*';/*Ponto inserido faz parte do corpo da Snake!*/
    }
    else{
        novo->next = NULL;
        novo->prev = NULL;
        d=novo;
    }
    return novo;
}

/*Função para inserir na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertRear (Deck *d, Point p, char field[][SIZE]) {
   
    Deck *novo = (Deck*)malloc(sizeof(Deck));
    Deck *aux = d;
    novo->p = p;
   
    if(d==NULL){
        novo->next = NULL;
        novo->prev = NULL;
        d = novo;
        return novo;
    }
    else{

        field[p.x][p.y] = '*';  /*Ponto inserido faz parte do corpo da Snake!*/
        novo->next = NULL;
        novo->prev = NULL;

        while(aux->next != NULL){
            aux = aux->next;  
        }
        
        novo->prev=aux;
        aux->next = novo;
        return d;
   }
}

/*Função para remover a cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteFront (Deck *d, char field[][SIZE]) {
  
   //field[x][y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/
   if (d==NULL){
      return NULL;
   }
   else{
      Deck *aux = d;
      d = d->next;
      d->prev = NULL;
      aux->next = NULL;
      field[aux->p.x][aux->p.y] = ' ';
      free(aux);
   
      return d;
   }
}

/*Função para remover a cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteRear (Deck *d, char field[][SIZE]) {
   
   //field[x][y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/
   if(d==NULL){
      return NULL;
   }
   else{
      Deck* aux  = d;
      
      while(aux->next != NULL){
         aux = aux->next;
      }
  
      field[aux->p.x][aux->p.y] = ' ';
      aux->prev->next = NULL;
      free(aux);
  
   return d;
   }
}