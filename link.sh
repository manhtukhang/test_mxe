#!/bin/bash
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/10-scale-bitmap-fonts.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/65-fonts-persian.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/20-unhint-small-vera.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/50-user.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/30-urw-aliases.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/60-latin.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/69-unifont.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/30-metric-aliases.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/90-synthetic.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/49-sansserif.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/45-latin.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/40-nonlatin.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/51-local.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/80-delicious.conf
rm $1/usr/i686-pc-mingw32/etc/fonts/conf.d/65-nonlatin.conf
rm $1/usr/bin/i686-pc-mingw32-libgcrypt-config
rm $1/usr/bin/i686-pc-mingw32-icu-config
rm $1/usr/bin/i686-pc-mingw32-pg_config
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/10-scale-bitmap-fonts.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/65-fonts-persian.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/20-unhint-small-vera.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/50-user.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/30-urw-aliases.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/60-latin.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/69-unifont.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/30-metric-aliases.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/90-synthetic.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/49-sansserif.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/45-latin.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/40-nonlatin.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/51-local.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/80-delicious.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/share/fontconfig/conf.avail/65-nonlatin.conf $1/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $1/usr/i686-pc-mingw32/bin/libgcrypt-config -T $1/usr/bin/i686-pc-mingw32-libgcrypt-config
ln -s $1/usr/i686-pc-mingw32/bin/icu-config -T $1/usr/bin/i686-pc-mingw32-icu-config
ln -s $1/usr/i686-pc-mingw32/bin/pg_config -T $1/usr/bin/i686-pc-mingw32-pg_config
