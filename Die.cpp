
#include "Die.h"

Die::Die(int numFaces) {
    for (int i = 1; i <= numFaces; i++) {
        m_faces.push_back(i);
    }
}

Die::Die(const std::vector<int>& faces) : m_faces(faces) {}

int Die::roll() {
    int index = std::rand() % m_faces.size();
    return m_faces[index];

}