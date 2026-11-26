# The app folder and release files

A local build creates and validates the complete title folder at
`dist/<TITLE_ID>/` and archives it as `dist/<TITLE_ID>.zip`.

```bash
make app
```

On Windows, `./build.ps1` runs the same build through WSL.

CI installs the [ps5-pkgkit v0.1.0 wheel](https://github.com/BlackBearRevived/ps5-pkgkit/releases/tag/v0.1.0)
with pip, verifies its pinned SHA-256, and builds a PS5 homebrew `.pkg` from the
same title folder for free Games-area apps using the fast Kraken preset.
CI verifies the PKG and publishes
both formats with their checksums when a new version tag is pushed. Media-area
apps release as a ZIP.

```bash
sha256sum -c SHA256SUMS
sha256sum -c PPSA99006.pkg.sha256
gh attestation verify PPSA99006.zip -R BlackBearRevived/ProsperoPuzzles
gh attestation verify PPSA99006.pkg -R BlackBearRevived/ProsperoPuzzles
```

Run each check with the corresponding download and checksum in the same
directory. The ZIP remains the format for extracting and uploading the
`<TITLE_ID>/` folder to `/data/homebrew`. See [Deployment](DEPLOYMENT.md).

Some earlier versions shipped `.ffpkg` (UFS2) and `.ffpfsc` (compressed)
images for folder deployment. If an old
`<TITLE_ID>.ffpkg` or `<TITLE_ID>.ffpfsc` is still in `/data/homebrew`, delete
it before installing the folder (`make undeploy` removes it together with
the folder): a folder and an image with the same title ID must not both be in
the loader's scan paths.
