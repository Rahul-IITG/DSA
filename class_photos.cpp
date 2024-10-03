bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
    int s=redShirtHeights.size();
    sort(redShirtHeights.begin(), redShirtHeights.end());
    sort(blueShirtHeights.begin(), blueShirtHeights.end());
    bool flag = false;

    if (redShirtHeights[0] < blueShirtHeights[0]) {
        flag = true;
    }
    if (redShirtHeights[0] == blueShirtHeights[0]) {
        return false;
    }

    for (int i=1;i<s;i++) {
        if (flag && redShirtHeights[i] < blueShirtHeights[i]) {
            continue;
        }
        else if (!flag && redShirtHeights[i] > blueShirtHeights[i]) {
            continue;
        }

        return false;
    }

    return true;
}