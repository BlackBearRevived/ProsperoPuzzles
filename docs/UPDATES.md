# Updates

Download the folder ZIP and `SHA256SUMS` from the
[latest release](https://github.com/BlackBearRevived/ProsperoPuzzles/releases/latest).
From the download directory, verify the file and its GitHub Actions provenance.

```bash
sha256sum --check SHA256SUMS
gh attestation verify PPSA99006.zip -R BlackBearRevived/ProsperoPuzzles
unzip PPSA99006.zip
```

Close the running game. Install the extracted `PPSA99006` folder with
your configured native homebrew loader. The library header and Settings show
the installed content version.

Game data uses the title's [sandbox storage](STORAGE.md), outside the installed
folder.
