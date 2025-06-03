#pragma once

int fibonacci_iterative(int sequence) {
    int result{0};
    int resultLast{0};
    int resultLastLast{0};

    if (sequence == 0) {
        return 0;
    }

    if (sequence == 1) {
        return 1;
    }

    resultLast = 1;

    for (int i = 2; i <= sequence; ++i) {
        result = resultLast + resultLastLast;

        resultLastLast = resultLast;
        resultLast = result;
    }

    return result;
}

int fibonacci_recursive(int sequence) {
    if (sequence == 0) {
        return 0;
    }

    if (sequence == 1) {
        return 1;
    }

    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
