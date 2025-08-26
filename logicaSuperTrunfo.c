#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char state[50];
    char code[10];
    char cityName[100];
    long population;
    double area;
    double gdp;
    int touristSpots;
    double populationDensity;
} Card;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void registerCard(Card *card, int cardNumber) {
    printf("\n=== Cadastro da Carta %d ===\n", cardNumber);
    
    printf("Digite o estado: ");
    fgets(card->state, sizeof(card->state), stdin);
    card->state[strcspn(card->state, "\n")] = '\0';
    
    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", card->code);
    clearInputBuffer();
    
    printf("Digite o nome da cidade: ");
    fgets(card->cityName, sizeof(card->cityName), stdin);
    card->cityName[strcspn(card->cityName, "\n")] = '\0';
    
    printf("Digite a populacao: ");
    scanf("%ld", &card->population);
    
    printf("Digite a area (km2): ");
    scanf("%lf", &card->area);
    
    printf("Digite o PIB (milhoes): ");
    scanf("%lf", &card->gdp);
    
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &card->touristSpots);
    clearInputBuffer();
    
    // CKDEV-NOTE: Calculate population density for comparison
    if (card->area > 0) {
        card->populationDensity = (double)card->population / card->area;
    } else {
        card->populationDensity = 0;
    }
}

void displayCard(Card *card, int cardNumber) {
    printf("\n=== Carta %d ===\n", cardNumber);
    printf("Estado: %s\n", card->state);
    printf("Codigo: %s\n", card->code);
    printf("Cidade: %s\n", card->cityName);
    printf("Populacao: %ld habitantes\n", card->population);
    printf("Area: %.2f km2\n", card->area);
    printf("PIB: %.2f milhoes\n", card->gdp);
    printf("Pontos Turisticos: %d\n", card->touristSpots);
    printf("Densidade Populacional: %.2f hab/km2\n", card->populationDensity);
}

void noviceLevel() {
    Card card1, card2;
    
    printf("\n========== NIVEL NOVATO ==========\n");
    printf("Voce comparara as cartas baseado em uma propriedade especifica.\n");
    
    registerCard(&card1, 1);
    registerCard(&card2, 2);
    
    displayCard(&card1, 1);
    displayCard(&card2, 2);
    
    printf("\n=== COMPARACAO DAS CARTAS ===\n");
    
    printf("\n1. POPULACAO:\n");
    if (card1.population > card2.population) {
        printf("   Vencedor: Carta 1 - %s (%ld habitantes)\n", card1.cityName, card1.population);
    } else if (card2.population > card1.population) {
        printf("   Vencedor: Carta 2 - %s (%ld habitantes)\n", card2.cityName, card2.population);
    } else {
        printf("   Empate! Ambas tem %ld habitantes\n", card1.population);
    }
    
    printf("\n2. AREA:\n");
    if (card1.area > card2.area) {
        printf("   Vencedor: Carta 1 - %s (%.2f km2)\n", card1.cityName, card1.area);
    } else if (card2.area > card1.area) {
        printf("   Vencedor: Carta 2 - %s (%.2f km2)\n", card2.cityName, card2.area);
    } else {
        printf("   Empate! Ambas tem %.2f km2\n", card1.area);
    }
    
    printf("\n3. PIB:\n");
    if (card1.gdp > card2.gdp) {
        printf("   Vencedor: Carta 1 - %s (%.2f milhoes)\n", card1.cityName, card1.gdp);
    } else if (card2.gdp > card1.gdp) {
        printf("   Vencedor: Carta 2 - %s (%.2f milhoes)\n", card2.cityName, card2.gdp);
    } else {
        printf("   Empate! Ambas tem PIB de %.2f milhoes\n", card1.gdp);
    }
    
    printf("\n4. PONTOS TURISTICOS:\n");
    if (card1.touristSpots > card2.touristSpots) {
        printf("   Vencedor: Carta 1 - %s (%d pontos)\n", card1.cityName, card1.touristSpots);
    } else if (card2.touristSpots > card1.touristSpots) {
        printf("   Vencedor: Carta 2 - %s (%d pontos)\n", card2.cityName, card2.touristSpots);
    } else {
        printf("   Empate! Ambas tem %d pontos turisticos\n", card1.touristSpots);
    }
    
    // CKDEV-NOTE: Population density - lower wins
    printf("\n5. DENSIDADE POPULACIONAL (menor vence):\n");
    if (card1.populationDensity < card2.populationDensity) {
        printf("   Vencedor: Carta 1 - %s (%.2f hab/km2)\n", card1.cityName, card1.populationDensity);
    } else if (card2.populationDensity < card1.populationDensity) {
        printf("   Vencedor: Carta 2 - %s (%.2f hab/km2)\n", card2.cityName, card2.populationDensity);
    } else {
        printf("   Empate! Ambas tem densidade de %.2f hab/km2\n", card1.populationDensity);
    }
}

void adventurerLevel() {
    Card card1, card2;
    int choice;
    
    printf("\n========== NIVEL AVENTUREIRO ==========\n");
    printf("Voce pode escolher qual atributo comparar!\n");
    
    registerCard(&card1, 1);
    registerCard(&card2, 2);
    
    displayCard(&card1, 1);
    displayCard(&card2, 2);
    
    do {
        printf("\n=== MENU DE COMPARACAO ===\n");
        printf("1. Comparar Populacao\n");
        printf("2. Comparar Area\n");
        printf("3. Comparar PIB\n");
        printf("4. Comparar Pontos Turisticos\n");
        printf("5. Comparar Densidade Populacional\n");
        printf("6. Comparar Todos\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &choice);
        
        printf("\n");
        
        switch(choice) {
            case 1:
                if (card1.population > card2.population) {
                    printf("VENCEDOR: Carta 1 - %s com %ld habitantes!\n", card1.cityName, card1.population);
                } else if (card2.population > card1.population) {
                    printf("VENCEDOR: Carta 2 - %s com %ld habitantes!\n", card2.cityName, card2.population);
                } else {
                    printf("EMPATE! Ambas tem %ld habitantes!\n", card1.population);
                }
                break;
                
            case 2:
                if (card1.area > card2.area) {
                    printf("VENCEDOR: Carta 1 - %s com %.2f km2!\n", card1.cityName, card1.area);
                } else if (card2.area > card1.area) {
                    printf("VENCEDOR: Carta 2 - %s com %.2f km2!\n", card2.cityName, card2.area);
                } else {
                    printf("EMPATE! Ambas tem %.2f km2!\n", card1.area);
                }
                break;
                
            case 3:
                if (card1.gdp > card2.gdp) {
                    printf("VENCEDOR: Carta 1 - %s com PIB de %.2f milhoes!\n", card1.cityName, card1.gdp);
                } else if (card2.gdp > card1.gdp) {
                    printf("VENCEDOR: Carta 2 - %s com PIB de %.2f milhoes!\n", card2.cityName, card2.gdp);
                } else {
                    printf("EMPATE! Ambas tem PIB de %.2f milhoes!\n", card1.gdp);
                }
                break;
                
            case 4:
                if (card1.touristSpots > card2.touristSpots) {
                    printf("VENCEDOR: Carta 1 - %s com %d pontos turisticos!\n", card1.cityName, card1.touristSpots);
                } else if (card2.touristSpots > card1.touristSpots) {
                    printf("VENCEDOR: Carta 2 - %s com %d pontos turisticos!\n", card2.cityName, card2.touristSpots);
                } else {
                    printf("EMPATE! Ambas tem %d pontos turisticos!\n", card1.touristSpots);
                }
                break;
                
            case 5:
                printf("(Menor densidade vence)\n");
                if (card1.populationDensity < card2.populationDensity) {
                    printf("VENCEDOR: Carta 1 - %s com %.2f hab/km2!\n", card1.cityName, card1.populationDensity);
                } else if (card2.populationDensity < card1.populationDensity) {
                    printf("VENCEDOR: Carta 2 - %s com %.2f hab/km2!\n", card2.cityName, card2.populationDensity);
                } else {
                    printf("EMPATE! Ambas tem densidade de %.2f hab/km2!\n", card1.populationDensity);
                }
                break;
                
            case 6:
                {
                    int card1Wins = 0, card2Wins = 0;
                    
                    if (card1.population > card2.population) card1Wins++;
                    else if (card2.population > card1.population) card2Wins++;
                    
                    if (card1.area > card2.area) card1Wins++;
                    else if (card2.area > card1.area) card2Wins++;
                    
                    if (card1.gdp > card2.gdp) card1Wins++;
                    else if (card2.gdp > card1.gdp) card2Wins++;
                    
                    if (card1.touristSpots > card2.touristSpots) card1Wins++;
                    else if (card2.touristSpots > card1.touristSpots) card2Wins++;
                    
                    if (card1.populationDensity < card2.populationDensity) card1Wins++;
                    else if (card2.populationDensity < card1.populationDensity) card2Wins++;
                    
                    printf("RESULTADO GERAL:\n");
                    printf("Carta 1 venceu %d categorias\n", card1Wins);
                    printf("Carta 2 venceu %d categorias\n", card2Wins);
                    
                    if (card1Wins > card2Wins) {
                        printf("\nVENCEDOR GERAL: Carta 1 - %s!\n", card1.cityName);
                    } else if (card2Wins > card1Wins) {
                        printf("\nVENCEDOR GERAL: Carta 2 - %s!\n", card2.cityName);
                    } else {
                        printf("\nEMPATE GERAL!\n");
                    }
                }
                break;
                
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
        
        if (choice != 0 && choice != 6) {
            printf("\nPressione Enter para continuar...");
            clearInputBuffer();
            getchar();
        }
        
    } while (choice != 0);
}

void masterLevel() {
    Card card1, card2;
    int attr1, attr2;
    
    printf("\n========== NIVEL MESTRE ==========\n");
    printf("Escolha DOIS atributos para comparacao complexa!\n");
    
    registerCard(&card1, 1);
    registerCard(&card2, 2);
    
    displayCard(&card1, 1);
    displayCard(&card2, 2);
    
    printf("\n=== ESCOLHA DOIS ATRIBUTOS ===\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Populacional\n");
    
    printf("\nPrimeiro atributo: ");
    scanf("%d", &attr1);
    
    printf("Segundo atributo: ");
    scanf("%d", &attr2);
    
    int card1Points = 0, card2Points = 0;
    char *attr1Name = "", *attr2Name = "";
    
    // CKDEV-NOTE: Complex nested comparison logic with ternary operators
    switch(attr1) {
        case 1:
            attr1Name = "Populacao";
            card1Points += (card1.population > card2.population) ? 1 : 
                          (card2.population > card1.population) ? 0 : 0;
            card2Points += (card2.population > card1.population) ? 1 : 0;
            break;
        case 2:
            attr1Name = "Area";
            card1Points += (card1.area > card2.area) ? 1 : 
                          (card2.area > card1.area) ? 0 : 0;
            card2Points += (card2.area > card1.area) ? 1 : 0;
            break;
        case 3:
            attr1Name = "PIB";
            card1Points += (card1.gdp > card2.gdp) ? 1 : 
                          (card2.gdp > card1.gdp) ? 0 : 0;
            card2Points += (card2.gdp > card1.gdp) ? 1 : 0;
            break;
        case 4:
            attr1Name = "Pontos Turisticos";
            card1Points += (card1.touristSpots > card2.touristSpots) ? 1 : 
                          (card2.touristSpots > card1.touristSpots) ? 0 : 0;
            card2Points += (card2.touristSpots > card1.touristSpots) ? 1 : 0;
            break;
        case 5:
            attr1Name = "Densidade Populacional";
            card1Points += (card1.populationDensity < card2.populationDensity) ? 1 : 
                          (card2.populationDensity < card1.populationDensity) ? 0 : 0;
            card2Points += (card2.populationDensity < card1.populationDensity) ? 1 : 0;
            break;
    }
    
    switch(attr2) {
        case 1:
            attr2Name = "Populacao";
            card1Points += (card1.population > card2.population) ? 2 : 
                          (card2.population > card1.population) ? 0 : 0;
            card2Points += (card2.population > card1.population) ? 2 : 0;
            break;
        case 2:
            attr2Name = "Area";
            card1Points += (card1.area > card2.area) ? 2 : 
                          (card2.area > card1.area) ? 0 : 0;
            card2Points += (card2.area > card1.area) ? 2 : 0;
            break;
        case 3:
            attr2Name = "PIB";
            card1Points += (card1.gdp > card2.gdp) ? 2 : 
                          (card2.gdp > card1.gdp) ? 0 : 0;
            card2Points += (card2.gdp > card1.gdp) ? 2 : 0;
            break;
        case 4:
            attr2Name = "Pontos Turisticos";
            card1Points += (card1.touristSpots > card2.touristSpots) ? 2 : 
                          (card2.touristSpots > card1.touristSpots) ? 0 : 0;
            card2Points += (card2.touristSpots > card1.touristSpots) ? 2 : 0;
            break;
        case 5:
            attr2Name = "Densidade Populacional";
            card1Points += (card1.populationDensity < card2.populationDensity) ? 2 : 
                          (card2.populationDensity < card1.populationDensity) ? 0 : 0;
            card2Points += (card2.populationDensity < card1.populationDensity) ? 2 : 0;
            break;
    }
    
    printf("\n=== RESULTADO DA COMPARACAO ===\n");
    printf("Atributo 1: %s (peso 1)\n", attr1Name);
    printf("Atributo 2: %s (peso 2)\n", attr2Name);
    printf("\nPontuacao Final:\n");
    printf("Carta 1 (%s): %d pontos\n", card1.cityName, card1Points);
    printf("Carta 2 (%s): %d pontos\n", card2.cityName, card2Points);
    
    printf("\n");
    
    // CKDEV-NOTE: Ternary operator for final winner determination
    char *winner = (card1Points > card2Points) ? card1.cityName : 
                   (card2Points > card1Points) ? card2.cityName : 
                   "EMPATE";
    
    if (strcmp(winner, "EMPATE") != 0) {
        printf("🏆 VENCEDOR: %s!\n", winner);
    } else {
        printf("🤝 EMPATE TECNICO!\n");
        
        if (card1.gdp != card2.gdp) {
            printf("\nDesempate por PIB:\n");
            char *tiebreaker = (card1.gdp > card2.gdp) ? card1.cityName : card2.cityName;
            printf("VENCEDOR FINAL: %s!\n", tiebreaker);
        } else {
            printf("Empate persistente!\n");
        }
    }
}

int main() {
    int levelChoice;
    
    printf("===================================\n");
    printf("   SUPER TRUNFO - PAISES\n");
    printf("   Comparacao de Cartas\n");
    printf("===================================\n");
    
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Nivel Novato\n");
        printf("2. Nivel Aventureiro\n");
        printf("3. Nivel Mestre\n");
        printf("0. Sair\n");
        printf("Escolha o nivel: ");
        scanf("%d", &levelChoice);
        clearInputBuffer();
        
        switch(levelChoice) {
            case 1:
                noviceLevel();
                break;
            case 2:
                adventurerLevel();
                break;
            case 3:
                masterLevel();
                break;
            case 0:
                printf("\nObrigado por jogar Super Trunfo!\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        
        if (levelChoice != 0) {
            printf("\nPressione Enter para voltar ao menu principal...");
            getchar();
        }
        
    } while (levelChoice != 0);
    
    // CKDEV-NOTE: Pause to prevent auto-close on Windows
    printf("\nPressione Enter para fechar o programa...");
    getchar();
    
    return 0;
}