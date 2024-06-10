#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { // Code du processus enfant
        close(pipefd[0]); // Ferme l'extrémité de lecture du pipe

        // Rediriger la sortie standard vers le pipe
        dup2(pipefd[1], STDOUT_FILENO); // dup2 copie pipefd[1] dans STDOUT_FILENO
        close(pipefd[1]); // Ferme l'extrémité d'écriture du pipe après la redirection

        // Exécution d'une commande (exemple : ls)
        execlp("ls", "ls", NULL);
    } else { // Code du processus parent
        close(pipefd[1]); // Ferme l'extrémité d'écriture du pipe

        // Attendre que le processus enfant termine
        wait(NULL);

        // Lecture des données du pipe (résultat de la commande ls)
        char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer));
        std::cout << "Résultat de la commande ls : \n" << buffer << std::endl;

        close(pipefd[0]); // Ferme l'extrémité de lecture du pipe
    }

    return 0;
}
