#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class DiningPhilosophers {
public:
    DiningPhilosophers() {

    }
    mutex mtx[5];
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        scoped_lock lck(mtx[philosopher], mtx[(philosopher + 1) % 5]);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
};

// https://leetcode.com/problems/the-dining-philosophers/

// no test code since the test was run via leetcode webui that handled the
// spawning of multiple threads to test