#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class CakeCutter {

private:

    int width;
    int height;

    set<int> verticalCuts;
    set<int> horizontalCuts;

    /*
    ============================================
            Find Maximum Segment
    ============================================
    */
    int getMaxSegment(
        const set<int>& cuts
    ) {

        int maximum = 0;

        auto previous = cuts.begin();
        auto current = previous;

        ++current;

        while (current != cuts.end()) {

            maximum = max(
                maximum,
                (*current - *previous)
            );

            ++previous;
            ++current;
        }

        return maximum;
    }

public:

    CakeCutter(
        int w,
        int h
    )
        : width(w),
          height(h)
    {

        /*
        ============================================
                Initial Borders
        ============================================
        */

        verticalCuts.insert(0);
        verticalCuts.insert(width);

        horizontalCuts.insert(0);
        horizontalCuts.insert(height);
    }

    /*
    ============================================
                Apply Cut
    ============================================
    */
    void makeCut(
        char type,
        int position
    ) {

        if (type == 'V') {

            verticalCuts.insert(position);
        }

        else if (type == 'H') {

            horizontalCuts.insert(position);
        }

        long long maxWidth =
            getMaxSegment(verticalCuts);

        long long maxHeight =
            getMaxSegment(horizontalCuts);

        long long area =
            maxWidth * maxHeight;

        cout
            << "Largest Remaining Piece Area = "
            << area
            << '\n';
    }
};

/*
=================================================
                    MAIN
=================================================
*/

int main() {

    int width;
    int height;
    int queries;

    cout
        << "Cake Width Height Queries:\n";

    cin
        >> width
        >> height
        >> queries;

    CakeCutter cake(
        width,
        height
    );

    cout << "\nCut Operations:\n";

    for (int i = 0; i < queries; ++i) {

        char cutType;
        int position;

        cin
            >> cutType
            >> position;

        cake.makeCut(
            cutType,
            position
        );
    }

    return 0;
}