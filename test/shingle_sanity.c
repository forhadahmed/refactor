// Test file for shingle filter sanity check
// Contains blocks with varying similarity levels

// Block A1: Base block (will be compared against variants)
void process_data_alpha() {
    int counter = 0;
    int accumulator = 0;
    for (int i = 0; i < 100; i++) {
        counter += i;
        accumulator += counter * 2;
        if (accumulator > 5000) {
            printf("Threshold reached at iteration %d\n", i);
            break;
        }
    }
    printf("Final counter: %d\n", counter);
    printf("Final accumulator: %d\n", accumulator);
}

// Block A2: Very similar to A1 (should match, ~95% similar)
void process_data_beta() {
    int counter = 0;
    int accumulator = 0;
    for (int i = 0; i < 100; i++) {
        counter += i;
        accumulator += counter * 2;
        if (accumulator > 5000) {
            printf("Threshold reached at iteration %d\n", i);
            break;
        }
    }
    printf("Final counter: %d\n", counter);
    printf("Final result: %d\n", accumulator);
}

// Block B1: Different structure (should NOT match A1/A2)
void handle_network_request() {
    char buffer[1024];
    int socket_fd = open_connection("localhost", 8080);
    if (socket_fd < 0) {
        perror("Connection failed");
        return;
    }
    while (read(socket_fd, buffer, sizeof(buffer)) > 0) {
        process_packet(buffer);
        send_acknowledgment(socket_fd);
    }
    close(socket_fd);
    printf("Connection closed\n");
}

// Block B2: Similar to B1 (should match B1, ~90% similar)
void handle_network_response() {
    char buffer[1024];
    int socket_fd = open_connection("localhost", 8080);
    if (socket_fd < 0) {
        perror("Connection failed");
        return;
    }
    while (read(socket_fd, buffer, sizeof(buffer)) > 0) {
        process_response(buffer);
        send_acknowledgment(socket_fd);
    }
    close(socket_fd);
    printf("Response handled\n");
}

// Block C1: Edge case - moderately similar to A1 (~70%, should NOT match)
void calculate_statistics() {
    int counter = 0;
    double average = 0.0;
    for (int i = 0; i < 100; i++) {
        counter += i;
        average = (double)counter / (i + 1);
        if (average > 50.0) {
            printf("Average exceeded threshold at %d\n", i);
        }
    }
    printf("Final average: %.2f\n", average);
    printf("Total count: %d\n", counter);
}

// Block D1: Completely different (should NOT match anything)
void render_graphics_frame() {
    GLfloat vertices[] = {0.0f, 0.5f, 0.0f, -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f};
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

// Block E1: Another pair for testing
void validate_user_input() {
    char username[64];
    char password[64];
    printf("Enter username: ");
    scanf("%63s", username);
    printf("Enter password: ");
    scanf("%63s", password);
    if (strlen(username) < 3 || strlen(password) < 8) {
        printf("Invalid credentials: too short\n");
        return;
    }
    if (authenticate(username, password)) {
        printf("Login successful for user: %s\n", username);
    } else {
        printf("Authentication failed\n");
    }
}

// Block E2: Similar to E1 (~85% similar)
void validate_admin_input() {
    char username[64];
    char password[64];
    printf("Enter admin name: ");
    scanf("%63s", username);
    printf("Enter admin key: ");
    scanf("%63s", password);
    if (strlen(username) < 3 || strlen(password) < 8) {
        printf("Invalid credentials: too short\n");
        return;
    }
    if (authenticate_admin(username, password)) {
        printf("Admin login successful: %s\n", username);
    } else {
        printf("Admin authentication failed\n");
    }
}
