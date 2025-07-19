class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        paths = set(folder)
        for f in folder:
            dirs = f.split('/')
            s = ""
            for dir in dirs[1:]:
                s += f"/{dir}"
                if s in paths and s != f:
                    paths.remove(f)
                    break
        return list(paths)