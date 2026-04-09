class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        arr = []

        for i in range(1,max(target)+1):
            if i in target:
                arr.append("Push")
            else:
                arr.append("Push")
                arr.append("Pop")

        return arr