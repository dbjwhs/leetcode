#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <iostream>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        auto revisions1 = parseRevisions(version1);
        auto revisions2 = parseRevisions(version2);

        // pad the shorter vector with zeros
        const size_t maxSize = std::max(revisions1.size(), revisions2.size());
        revisions1.resize(maxSize, 0);
        revisions2.resize(maxSize, 0);

        // compare revision by revision
        for (size_t ndx = 0; ndx < maxSize; ++ndx) {
            if (revisions1[ndx] < revisions2[ndx]) {
                return -1;
            } else if (revisions1[ndx] > revisions2[ndx]) {
                return 1;
            }
        }
        return 0;
    }

private:
    std::vector<int> parseRevisions(const std::string& version) {
        std::vector<int> revisions;
        std::stringstream ss(version);
        std::string revision;

        while (std::getline(ss, revision, '.')) {
            // convert to int automatically handles leading zeros
            revisions.push_back(std::stoi(revision));
        }
        return revisions;
    }
};

// tests
namespace Tests {
    void testBasicComparisons() {
        Solution solution;

        // version1 < version2
        assert(solution.compareVersion("1.2", "1.10") == -1);

        // equal versions with leading zeros
        assert(solution.compareVersion("1.01", "1.001") == 0);

        // different number of revisions
        assert(solution.compareVersion("1.0", "1.0.0.0") == 0);

        std::cout << "Basic comparisons: PASSED\n";
    }

    void testEdgeCases() {
        Solution solution;

        // single digit versions
        assert(solution.compareVersion("1", "2") == -1);
        assert(solution.compareVersion("2", "1") == 1);
        assert(solution.compareVersion("1", "1") == 0);

        // leading zeros in single revision
        assert(solution.compareVersion("01", "1") == 0);
        assert(solution.compareVersion("001", "1") == 0);

        // multiple leading zeros
        assert(solution.compareVersion("1.000", "1.0") == 0);
        assert(solution.compareVersion("1.000", "1.1") == -1);

        // longer vs shorter versions
        assert(solution.compareVersion("1.0.0", "1") == 0);
        assert(solution.compareVersion("1.0.1", "1") == 1);
        assert(solution.compareVersion("1", "1.0.1") == -1);

        std::cout << "Edge cases: PASSED\n";
    }

    void testComplexVersions() {
        Solution solution;

        // multi-digit revisions
        assert(solution.compareVersion("1.23.45", "1.23.44") == 1);
        assert(solution.compareVersion("1.23.45", "1.24.1") == -1);

        // large numbers (within 32-bit int range)
        assert(solution.compareVersion("2147483647", "2147483646") == 1);
        assert(solution.compareVersion("1.2147483647", "1.2147483647") == 0);

        // many revisions
        assert(solution.compareVersion("1.2.3.4.5", "1.2.3.4.6") == -1);
        assert(solution.compareVersion("1.2.3.4.5.0.0", "1.2.3.4.5") == 0);

        std::cout << "Complex versions: PASSED\n";
    }

    void testBoundaryConditions() {
        Solution solution;

        // zero revisions
        assert(solution.compareVersion("0", "0.0.0") == 0);
        assert(solution.compareVersion("0.0", "0") == 0);
        assert(solution.compareVersion("0.1", "0.0") == 1);

        // mixed zeros and non-zeros
        assert(solution.compareVersion("1.0.0.1", "1.0.0.0") == 1);
        assert(solution.compareVersion("1.0.0.0", "1.0.0.1") == -1);

        // all zeros vs single zero
        assert(solution.compareVersion("0.0.0.0", "0") == 0);

        std::cout << "Boundary conditions: PASSED\n";
    }

    void runAllTests() {
        std::cout << "Running comprehensive test suite...\n\n";

        testBasicComparisons();
        testEdgeCases();
        testComplexVersions();
        testBoundaryConditions();

        std::cout << "\nAll tests passed successfully!\n";
    }
}

// function to show usage
void demonstrateUsage() {
    Solution solution;

    std::cout << "\n=== Version Comparison Demo ===\n";

    struct TestCase {
        std::string v1, v2;
        std::string expected;
    };

    std::vector<TestCase> demos = {
        {"1.2", "1.10", "v1 < v2"},
        {"1.01", "1.001", "v1 == v2"},
        {"1.0", "1.0.0.0", "v1 == v2"},
        {"2.0.1", "2.0.0", "v1 > v2"},
        {"1.2.3", "1.2.4", "v1 < v2"}
    };

    for (const auto& test : demos) {
        int result = solution.compareVersion(test.v1, test.v2);
        std::cout << "compareVersion(\"" << test.v1 << "\", \"" << test.v2 << "\") = "
                  << result << " (" << test.expected << ")\n";
    }
}

int main() {
    Tests::runAllTests();
    demonstrateUsage();
    return 0;
}