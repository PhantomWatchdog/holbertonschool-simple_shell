#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    char *buffer = NULL;    /*Pointeur pour stocker la ligne d'entré*/
    size_t size = 0;        /*Taille initiale du buffer*/
    char *argv[64];         /* Tableau pour stocker les arguments de la commande*/
    int status, argc;
    char *token;
    pid_t pid;

    while (1)
    {
        printf("LELE$ ");  /* Affichage du prompt du shell*/
        
        /*Lecture de la commande entrée par l'utilisateu*/
        if (getline(&buffer, &size, stdin) == -1)
        {
            perror("getline");  /* Gestion de l'erreur de lecture*/
            exit(EXIT_FAILURE);
        }
        
        /*Supprimer le caractère de nouvelle ligne à la fin de la commde*/
	buffer[strcspn(buffer, "\n")] = '\0';
        
        /*Découper la commande en argument*/
        argc = 0;
        token = strtok(buffer, " ");

        while (token != NULL && argc < 63)  /* Limiter le nombre d'arguments à 6*/
        {
            argv[argc++] = token;
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL;  /*Dernier élément du tableau doit être NUL*/
        
        /* Ignorer les lignes vides*/
        if (argc == 0)
            continue;
        
        /* Créer un processus fils pour exécuter la comman*/
        pid = fork();
        
        if (pid == -1)
        {
            perror("fork");  /*Gestion de l'erreur de création du processus fil*/
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            /*Processus fils : exécution de la command*/
            execvp(argv[0], argv);
            
            /* En cas d'échec de l'exécution de la comman*/
            perror("execvp");
            exit(EXIT_FAILURE);
        }
        else
        {
            /*Processus parent : attente de la fin du processus fils*/
            waitpid(pid, &status, 0);
        }
    }
    
    free(buffer);  /*Libérer la mémoire allouée pour le buf*/
    return 0;
}
