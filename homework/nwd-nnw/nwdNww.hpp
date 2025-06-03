#pragma once

int NWD(int lhs, int rhs) {
    if ((lhs == 0) && (rhs == 0))
    {
        return 0;
    }
    else if ((lhs == 0) && (rhs != 0)) {
        return std::abs(rhs);
    }
    else if ((lhs != 0) && (rhs == 0))
    {
        return std::abs(lhs);
    }

    int lastDivider{1};
    int malhsDivider{std::min(std::abs(lhs), std::abs(rhs))};

    for (int i = 1; i <= malhsDivider; ++i) {
        if (((lhs % i) == 0) && ((rhs % i) == 0)) {
            lastDivider = i;
        }
    }

    return lastDivider;
}

int NWW(int lhs, int rhs) {
    if((lhs == 0) && (rhs == 0))
    {
        return 0;
    }
    return std::abs(lhs * rhs) / NWD(lhs, rhs);
}