# fileSplitter(ファイル分割プログラム)

# 目的
githubでは最大100MBのファイルしかアップロードできないため、matlabのグラフデータなどを保管できない。2次元グラフであれば画像で十分かもしれないが、3次元グラフの場合はそうはいかない。  
そこで、100MB=95.36743164MiB毎に分割するプログラムを開発することにした。

# 作成手順
省略する。プログラムのソース[filesplitter.c](filesplitter.c)自体にコメントで説明を付しているので必要に応じて参考にされたい。

# 使用方法(ファイルを分割したい場合)
1. gccなどで[filesplitter.c](filesplitter.c)をコンパイルする。  
64bit版windowsを使用している場合は[レポジトリにあるfilesplitter.exe](filesplitter.exe)が動くかもしれない。  
2. 1と同じディレクトリに100MBを超えるファイルをコピーまたは移動する。  
3. CUIで `filesplitter filename` を実行する。但しfilenameには2のファイル名(拡張子付き)を当てはめる。  
4. filename_0、filename_1、・・・、およびfilename.17ec084といったファイルが生成される。これらはすべて100MB以内なのでgithubにアップロードすることが可能である。  

# 使用方法(分割されたファイルを元に戻す(合成)場合)
1. gccなどで[filesplitter.c](filesplitter.c)をコンパイルする。  
64bit版windowsを使用している場合は[レポジトリにあるfilesplitter.exe](filesplitter.exe)が動くかもしれない。  
2.  
 


# 参考
http://www.c-tipsref.com/tips/file/fgetc.html  
http://www9.plala.or.jp/sgwr-t/c/sec17.html