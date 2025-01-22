#include <stdio.h>
#include <string.h>

// Define the Movie structure
typedef struct {
    char movieName[50];
    int duration;
    char category[10];
    int ticketCost;
} Movie;

// Function to get movie details
Movie GetMovieDetails() {
    Movie m;
    printf("Enter movie name: ");
    scanf(" %[^\n]s", m.movieName);
    printf("Enter movie duration (in minutes): ");
    scanf("%d", &m.duration);
    printf("Enter movie category (2D/3D): ");
    scanf("%s", m.category);
    m.ticketCost = 0;
    return m;
}

// Function to get circle details
char* GetCircleDetails() {
    static char circle[10];
    printf("Enter circle type (gold/silver): ");
    scanf("%s", circle);
    return circle;
}

// Function to calculate ticket cost
int CalculateTicketCost(Movie *m, char circle[]) {
    if (strcmp(circle, "gold") == 0) {
        if (strcmp(m->category, "2D") == 0) {
            m->ticketCost = 300;
            return 0;
        } else if (strcmp(m->category, "3D") == 0) {
            m->ticketCost = 500;
            return 0;
        } else {
            return -1; // Invalid category
        }
    } else if (strcmp(circle, "silver") == 0) {
        if (strcmp(m->category, "2D") == 0) {
            m->ticketCost = 250;
            return 0;
        } else if (strcmp(m->category, "3D") == 0) {
            m->ticketCost = 450;
            return 0;
        } else {
            return -1; // Invalid category
        }
    } else {
        if (strcmp(m->category, "2D") != 0 && strcmp(m->category, "3D") != 0) {
            return -3; // Both circle and category invalid
        }
        return -2; // Invalid circle
    }
}

int main() {
    Movie m = GetMovieDetails();
    char *circle = GetCircleDetails();

    int result = CalculateTicketCost(&m, circle);

    if (result == 0) {
        printf("The ticket cost is Rs. %d\n", m.ticketCost);
    } else if (result == -1) {
        printf("Sorry, there is no %s type of category in the theatre.\n", m.category);
    } else if (result == -2) {
        printf("Sorry, the circle is invalid.\n");
    } else if (result == -3) {
        printf("Sorry, both circle and category are invalid.\n");
    }

    return 0;
}
