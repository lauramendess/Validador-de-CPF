/*
Aluna: Laura Mendes Goncalves
Universidade Federal de Catalao
Data de criacao: 26/06/2023. Data de modificacao: 26/03/2025
Ciencia da Computacao, laboratorio de Programacao 1 e Algoritmo e Programacao de Computadores 1
Matricula: 202301133
*/

#include <stdio.h>
#include <string.h>

// Função para verificar se o tamanho do CPF é válido
int verificarTamanho(char cpf[]) {
	return strlen(cpf) == 11;
}

// Função para verificar se todos os caracteres do CPF são números
int verificarDigitos(char cpf[]) {
	for (int i = 0; i < 11; i++) {
		if (cpf[i] < '0' || cpf[i] > '9') {
			return 0;
		}
	}
	return 1;
}

// Função para calcular o primeiro dígito verificador
int calcularPrimeiroDigito(char cpf[]) {
	int soma = 0;
	for (int i = 0; i < 9; i++) {
		soma += (cpf[i] - '0') * (10 - i);
	}
	soma %= 11;
	return (soma < 2) ? 0 : 11 - soma;
}

// Função para calcular o segundo dígito verificador
int calcularSegundoDigito(char cpf[]) {
	int soma = 0;
	for (int i = 0; i < 10; i++) {
		soma += (cpf[i] - '0') * (11 - i);
	}
	soma %= 11;
	return (soma < 2) ? 0 : 11 - soma;
}

// Função para verificar se todos os números do CPF são iguais
int verificarNumerosIguais(char cpf[]) {
	for (int i = 1; i < 11; i++) {
		if (cpf[i] != cpf[0]) {
			return 1;
		}
	}
	return 0;
}

int main() {
	char cpf[12];
	printf("Informe o CPF, com apenas digitos, para verificar se eh valido ou invalido:\n");
	gets(cpf);

	if (!verificarTamanho(cpf)) {
		printf("O CPF eh invalido!");
		return 1;
	}

	if (!verificarDigitos(cpf)) {
		printf("O CPF eh invalido!");
		return 1;
	}

	int primeiroDigito = calcularPrimeiroDigito(cpf);
	if (cpf[9] - '0' != primeiroDigito) {
		printf("O CPF eh invalido!");
		return 1;
	}

	int segundoDigito = calcularSegundoDigito(cpf);
	if (cpf[10] - '0' != segundoDigito) {
		printf("O CPF eh invalido!");
		return 1;
	}

	if (!verificarNumerosIguais(cpf)) {
		printf("O CPF eh invalido!");
		return 1;
	}

	printf("O CPF eh valido!");
	return 0;
}