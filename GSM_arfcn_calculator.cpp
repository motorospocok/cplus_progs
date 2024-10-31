#include <iostream>

double calculateGSM900DownlinkFrequency(int arfcn) {
    return 935.0 + 0.2 * (arfcn - 1);
}

double calculateGSM900UplinkFrequency(int arfcn) {
    return 890.0 + 0.2 * (arfcn - 1);
}

double calculateGSM1800DownlinkFrequency(int arfcn) {
    return 1805.2 + 0.2 * (arfcn - 512);
}

double calculateGSM1800UplinkFrequency(int arfcn) {
    return 1710.2 + 0.2 * (arfcn - 512);
}

int main() {
    int arfcn;
    std::cout << "Enter GSM ARFCN: ";
    std::cin >> arfcn;

    // GSM 900 Frequencies
    if (arfcn >= 1 && arfcn <= 124) {
        double gsm900Downlink = calculateGSM900DownlinkFrequency(arfcn);
        double gsm900Uplink = calculateGSM900UplinkFrequency(arfcn);

        std::cout << "GSM 900 Downlink Frequency: " << gsm900Downlink << " MHz" << std::endl;
        std::cout << "GSM 900 Uplink Frequency: " << gsm900Uplink << " MHz" << std::endl;
    } else {
        std::cout << "ARFCN is out of range for GSM 900." << std::endl;
    }

    // GSM 1800 Frequencies
    if (arfcn >= 512 && arfcn <= 885) {
        double gsm1800Downlink = calculateGSM1800DownlinkFrequency(arfcn);
        double gsm1800Uplink = calculateGSM1800UplinkFrequency(arfcn);

        std::cout << "GSM 1800 Downlink Frequency: " << gsm1800Downlink << " MHz" << std::endl;
        std::cout << "GSM 1800 Uplink Frequency: " << gsm1800Uplink << " MHz" << std::endl;
    } else {
        std::cout << "ARFCN is out of range for GSM 1800." << std::endl;
    }

    return 0;
}
