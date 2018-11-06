if exist sandboxdoc.zip del sandboxdoc.zip
if exist build          rmdir /s /q build

pip install sphinx  --user
call make.bat htmlhelp

"C:\Program Files (x86)\HTML Help Workshop\hhc.exe" build\htmlhelp\sandboxdoc.hhp

copy /Y build\htmlhelp\sandboxdoc.chm .
"C:\Program Files\7-Zip\7z.exe" a sandboxdoc.zip sandboxdoc.chm
