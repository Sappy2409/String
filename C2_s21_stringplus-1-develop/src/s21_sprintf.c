#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  flags f;
  s21_memset(&f, 0, sizeof(flags));
  va_list factor;
  va_start(factor, format);
  char *helpstr = str;
  while (*format) {
    if (*format != '%') {
      *helpstr = *format;
      helpstr++;
      format++;
      continue;
    } else {
      format++;
      s21_memset(&f, 0, sizeof(flags));
    }
    format = get_flags(format, &f);
    format = get_width(format, &f);
    format = get_precision(format, &f);
    format = get_length(format, &f);
    f.specifier = *format;
    format++;
    char buff[512] = {'\0'};
    switch (f.specifier) {
      case 'd':
        specdfunc(f, buff, factor);
        break;
      case 'u':
        specufunc(f, buff, factor);
        break;
      case 'c':
        speccfunc(f, buff, factor);
        break;
      case 's':
        specsfunc(f, buff, factor);
        break;
      case 'f':
        specffunc(f, buff, factor);
        break;
      case '%':
        specprocfunc(buff);
        break;
    }
    for (int i = 0; buff[i]; i++, helpstr++) *helpstr = buff[i];
  }
  *helpstr = '\0';
  va_end(factor);
  return helpstr - str;
}

void specprocfunc(char *buff) { s21_memset(buff, '%', 1); }

void specffunc(flags f, char *buff, va_list factor) {
  double val = va_arg(factor, double);
  char bufffordouble[512] = {'\0'};
  s21_doubletostring(bufffordouble, val, f);
  if (f.minus && f.width > (int)s21_strlen(bufffordouble)) {
    s21_memset(buff, ' ', f.width);
    int i = 0;
    while (bufffordouble[i]) {
      *buff = bufffordouble[i];
      buff++;
      i++;
    }
  } else if (!f.minus && f.width > (int)s21_strlen(bufffordouble)) {
    s21_memset(buff, ' ', f.width);
    int j = 0;
    while (bufffordouble[j]) {
      *(buff + f.width - s21_strlen(bufffordouble)) = bufffordouble[j];
      buff++;
      j++;
    }
  } else {
    int k = 0;
    while (bufffordouble[k]) {
      *buff = bufffordouble[k];
      buff++;
      k++;
    }
  }
}

void specsfunc(flags f, char *buff, va_list factor) {
  char *val = va_arg(factor, char *);
  if (f.minus) {
    s21_memset(buff, ' ', f.width);
    if (!f.is_precision_set) {
      f.precision = s21_strlen(val);
    }
    while (*val && f.precision > 0) {
      *buff = *val;
      buff++;
      val++;
      f.precision--;
    }
  } else {
    if ((int)s21_strlen(val) < f.width) {
      if (!f.is_precision_set) {
        s21_memset(buff, ' ', f.width - s21_strlen(val));
      } else {
        if (f.precision < (int)s21_strlen(val)) {
          s21_memset(buff, ' ', f.width - f.precision);
        } else {
          s21_memset(buff, ' ', f.width - s21_strlen(val));
        }
      }
    }
    if (f.is_precision_set) {
      s21_strncat(buff, val, f.precision);
    } else {
      s21_strncat(buff, val, s21_strlen(val));
    }
  }
}

void speccfunc(flags f, char *buff, va_list factor) {
  if (f.length == 'l') {
    wchar_t val;
    val = va_arg(factor, wchar_t);
    s21_memset(buff, ' ', f.width);
    if (f.minus) {
      //*buff=val;
      wctomb(buff, val);
    } else {
      wctomb(buff + s21_strlen(buff) - 1, val);
      //*(buff+s21_strlen(buff)-1)=val;
    }
  } else {
    char val;
    val = va_arg(factor, int);
    s21_memset(buff, ' ', f.width);
    if (f.minus) {
      *buff = val;
    } else {
      if (!f.width) {
        *buff = val;
      } else {
        *(buff + s21_strlen(buff) - 1) = val;
      }
    }
  }
}

void specdfunc(flags f, char *buff, va_list factor) {
  int val = va_arg(factor, int);
  if (f.length == 'h') {
    val = (short int)val;
  }
  s21_inttostr(buff, val, f);
}

void specufunc(flags f, char *buff, va_list factor) {
  unsigned val = va_arg(factor, unsigned);
  if (f.length == 'h') {
    val = (unsigned short)val;
  }
  s21_uinttostr(buff, val, f);
}

const char *get_flags(const char *format, flags *f) {
  while (*format == '-' || *format == '+' || *format == ' ') {
    switch (*format) {
      case '-':
        f->minus = 1;
        break;
      case '+':
        f->plus = 1;
        break;
      case ' ':
        f->space = 1;
        break;
    }
    format++;
  }
  return format;
}

const char *get_width(const char *format, flags *f) {
  if (s21_isdigit(*format)) {
    char tmp[512] = {'\0'};
    for (int i = 0; s21_isdigit(*format); i++, format++) tmp[i] = *format;
    f->width = s21_strtoint(tmp);
  }
  return format;
}

const char *get_precision(const char *format, flags *f) {
  if (*format == '.') {
    f->is_precision_set = 1;
    format++;
  }
  if (s21_isdigit(*format)) {
    char tmp[512] = {'\0'};
    for (int i = 0; s21_isdigit(*format); i++, format++) tmp[i] = *format;
    f->precision = s21_strtoint(tmp);
  }
  return format;
}

const char *get_length(const char *format, flags *f) {
  switch (*format) {
    case 'h':
      f->length = 'h';
      format++;
      break;
    case 'l':
      f->length = 'l';
      format++;
      break;
  }
  return format;
}

int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }

int s21_strtoint(char *str) {
  int res = 0;
  while (*str && *str >= '0' && *str <= '9') {
    res = res * 10 + (*str - '0');
    str++;
  }
  return res;
}

char *s21_inttostr(char *str, int n, flags f) {
  char *res = str;
  int i = 0;
  int counter = 0;
  char tmp;
  if (n < 0) {
    n = -n;
    counter = 1;
  }
  while (n > 0 || f.precision > 0) {
    *(res + i) = (n % 10) + 48;
    n = n / 10;
    i++;
    f.precision--;
  }
  if (counter == 1) {
    *(res + i) = '-';
    i++;
  } else {
    if (f.plus) {
      *(res + i) = '+';
      i++;
    } else if (f.space) {
      *(res + i) = ' ';
      i++;
    }
  }
  if (!f.minus) {
    while (i < f.width) {
      *(res + i) = ' ';
      i++;
    }
  }
  int j = i;
  i--;
  while (res < str + i) {
    tmp = *res;
    *res = *(str + i);
    *(str + i) = tmp;
    res++;
    i--;
  }
  if (f.minus) {
    while (j < f.width) {
      *(str + j) = ' ';
      j++;
    }
  }
  return str;
}

char *s21_uinttostr(char *str, unsigned n, flags f) {
  char *res = str;
  int i = 0;
  char tmp;
  while (n > 0 || f.precision > 0) {
    *(res + i) = (n % 10) + 48;
    n = n / 10;
    i++;
    f.precision--;
  }
  if (f.plus) {
    *(res + i) = '+';
    i++;
  }
  if (f.space && !f.plus) {
    *(res + i) = ' ';
    i++;
  }

  if (!f.minus) {
    while (i < f.width) {
      *(res + i) = ' ';
      i++;
    }
  }
  int j = i;
  i--;
  while (res < str + i) {
    tmp = *res;
    *res = *(str + i);
    *(str + i) = tmp;
    res++;
    i--;
  }
  if (f.minus) {
    while (j < f.width) {
      *(str + j) = ' ';
      j++;
    }
  }
  return str;
}

char *s21_doubletostring(char *str, double n, flags f) {
  int leftpart = (int)n;
  double rightpart = n - leftpart;
  char helpright[100] = {'\0'};
  int i = 0;
  flags fd;
  s21_memset(&fd, 0, sizeof(flags));
  if (f.plus) {
    fd.plus = 1;
  }
  if (f.space) {
    fd.space = 1;
  }
  if (rightpart < 0) {
    rightpart = -rightpart;
  }
  if (!f.is_precision_set) {
    f.precision = 6;
  }
  while (i < f.precision) {
    rightpart = rightpart * 10;
    // helpright[i] = (fmod(floor(rightpart), 10)) + 48;
    i++;
  }
  i--;
  rightpart = roundl(rightpart);
  while (i >= 0) {
    helpright[i] = (fmod(floor(rightpart), 10)) + 48;
    rightpart = rightpart / 10;
    i--;
  }
  flags fd1;
  s21_memset(&fd1, 0, sizeof(flags));
  s21_inttostr(helpright, (int)rightpart, fd1);
  char tochka[] = ".";
  char helpleft[100] = {'\0'};
  s21_inttostr(helpleft, leftpart, fd);
  s21_strncat(str, helpleft, s21_strlen(helpleft));
  if (!f.is_precision_set || f.precision != 0) {
    s21_strncat(str, tochka, s21_strlen(tochka));
  }
  s21_strncat(str, helpright, s21_strlen(helpright));
  return str;
}
