set number " show line numbers
set hlsearch " turn on highlighted searching
set expandtab " set the tab character to 4 spaces
set tabstop=4 " have it replace with 4 spaces
set shiftwidth=4 " tabs are 4 spaces (for shifting)
set softtabstop=4 " ionno, more tab things...
set directory=~/.vim/swap " set swap file directory 
"set spell spelllang=en_us " turn on spellcheck

"commands for python testing/running
command Py sp!python <C-r>%

"commands for latex compilation/opening
command LL !pdflatex %
"command LL !pdflatex expand("%:t")
command LO !gnome-open <C-r>%:r.pdf
"command LO !gnome-open expand("%:t:r").pdf

"commands for ghc
command GHC !ghc expand("%:t")

" allow use of ;; or jj instead of <Esc> to exit insert mode
noremap! ;; <Esc>
noremap! jj <Esc>

" move up and down by viewed lines (if word wrapped, it'll go
"   by the apparent lines instead of by newlines in the file)
"noremap! j gj
"noremap! k gk
noremap <Down> gj
noremap <Up> gk

"let :ghc :!ghc
"let :ghci :!ghci

"set ghc=ghc
"set ghci=ghci

"for vim-latexsuite
"filetype plugin on
"set grepprg=grep\ -nH\ $*
"filetype indent on
"let g:tex_flavor='latex'

" You may already have the following two on, please check
" syntax on
" filetype plugin on

" This assumes that ghc is in your path, if it is not, or you
" wish to use a specific version of ghc, then please change
" the ghc below to a full path to the correct one
"au BufEnter *.hs compiler ghc

" For this section both of these should be set to your
" browser and ghc of choice, I used the following
" two vim lines to get those paths:
" :r!which google-chrome
" :r!whigh ghc
"let g:haddock_browser = "/usr/bin/google-chrome"
"let g:ghc = "/usr/bin/ghc"

"attempt to make ghc a thing in vim
"noremap! :ghc :!ghc
