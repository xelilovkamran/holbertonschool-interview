
def canUnlockAll(boxes):
    unlockedBoxes = set()
    for i, element in enumerate(boxes):
        for j, box in enumerate(element):
            if box != i and box < len(boxes):
                unlockedBoxes.add(box)
    unlockedBoxes.add(0)
    
    for index, indexedBox in enumerate(unlockedBoxes):
        if index != indexedBox and index != 0:
            return False
    return True        
