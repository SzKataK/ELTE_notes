// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "while.tab.hh"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 136 "while.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_expression: // expression
        value.copy< expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_expression: // expression
        value.move< expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.move< expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.copy< expression > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.move< expression > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< expression > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // start: PRG ID declarations BEG commands END
#line 54 "while.y"
    {
        output_code(yystack_[1].value.as < std::string > ());
    }
#line 703 "while.tab.cc"
    break;

  case 5: // declaration: BOO ID
#line 67 "while.y"
    {
        declare(yystack_[1].location.begin.line, yystack_[0].value.as < std::string > (), boolean);
    }
#line 711 "while.tab.cc"
    break;

  case 6: // declaration: NAT ID
#line 72 "while.y"
    {
        declare(yystack_[1].location.begin.line, yystack_[0].value.as < std::string > (), natural);
    }
#line 719 "while.tab.cc"
    break;

  case 7: // commands: %empty
#line 79 "while.y"
    {
        yylhs.value.as < std::string > () = "";
    }
#line 727 "while.tab.cc"
    break;

  case 8: // commands: commands command
#line 84 "while.y"
    {
        yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + yystack_[0].value.as < std::string > ();
    }
#line 735 "while.tab.cc"
    break;

  case 9: // command: REA OP ID CL
#line 91 "while.y"
    {
        get_type(yystack_[1].location.begin.line, yystack_[1].value.as < std::string > ());
        yylhs.value.as < std::string > () = read_command(yystack_[1].value.as < std::string > ());
    }
#line 744 "while.tab.cc"
    break;

  case 10: // command: WRI OP expression CL
#line 97 "while.y"
    {
        yylhs.value.as < std::string > () = write_command(yystack_[1].value.as < expression > ().typ, yystack_[1].value.as < expression > ().code);
    }
#line 752 "while.tab.cc"
    break;

  case 11: // command: ID ASN expression
#line 102 "while.y"
    {
        check_assignment(yystack_[2].location.begin.line, yystack_[2].value.as < std::string > (), yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < std::string > () = assign_command(yystack_[2].value.as < std::string > (), yystack_[0].value.as < expression > ().typ, yystack_[0].value.as < expression > ().code);
    }
#line 761 "while.tab.cc"
    break;

  case 12: // command: IF expression THE commands EIF
#line 108 "while.y"
    {
        check_condition(yystack_[4].location.begin.line, yystack_[3].value.as < expression > ().typ);
        yylhs.value.as < std::string > () = if1_command(yystack_[3].value.as < expression > ().code, yystack_[1].value.as < std::string > ());
    }
#line 770 "while.tab.cc"
    break;

  case 13: // command: IF expression THE commands ELS commands EIF
#line 114 "while.y"
    {
        check_condition(yystack_[6].location.begin.line, yystack_[5].value.as < expression > ().typ);
        yylhs.value.as < std::string > () = if2_command(yystack_[5].value.as < expression > ().code, yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::string > ());
    }
#line 779 "while.tab.cc"
    break;

  case 14: // command: WHI expression DO commands DON
#line 120 "while.y"
    {
        check_condition(yystack_[4].location.begin.line, yystack_[3].value.as < expression > ().typ);
        yylhs.value.as < std::string > () = while_command(yystack_[3].value.as < expression > ().code, yystack_[1].value.as < std::string > ());
    }
#line 788 "while.tab.cc"
    break;

  case 15: // expression: NUM
#line 128 "while.y"
    {
        yylhs.value.as < expression > () = literal_expression(natural, yystack_[0].value.as < std::string > ());
    }
#line 796 "while.tab.cc"
    break;

  case 16: // expression: TRU
#line 133 "while.y"
    {
        yylhs.value.as < expression > () = literal_expression(boolean, "1");
    }
#line 804 "while.tab.cc"
    break;

  case 17: // expression: FAL
#line 138 "while.y"
    {
        yylhs.value.as < expression > () = literal_expression(boolean, "0");
    }
#line 812 "while.tab.cc"
    break;

  case 18: // expression: ID
#line 143 "while.y"
    {
        yylhs.value.as < expression > () = id_expression(yystack_[0].location.begin.line, yystack_[0].value.as < std::string > ());
    }
#line 820 "while.tab.cc"
    break;

  case 19: // expression: expression ADD expression
#line 148 "while.y"
    {
        check_binop(yystack_[1].location.begin.line, "+", natural, natural, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = binop_expression("+", natural, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 829 "while.tab.cc"
    break;

  case 20: // expression: expression SUB expression
#line 154 "while.y"
    {
        check_binop(yystack_[1].location.begin.line, "-", natural, natural, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = binop_expression("-", natural, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 838 "while.tab.cc"
    break;

  case 21: // expression: expression MUL expression
#line 160 "while.y"
    {
        check_binop(yystack_[1].location.begin.line, "*", natural, natural, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = binop_expression("*", natural, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 847 "while.tab.cc"
    break;

  case 22: // expression: expression DIV expression
#line 166 "while.y"
    {
        check_binop(yystack_[1].location.begin.line, "/", natural, natural, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = binop_expression("/", natural, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 856 "while.tab.cc"
    break;

  case 23: // expression: expression MOD expression
#line 172 "while.y"
    {
        check_binop(yystack_[1].location.begin.line, "%", natural, natural, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = binop_expression("%", natural, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 865 "while.tab.cc"
    break;

  case 24: // expression: expression LS expression
#line 178 "while.y"
    {
        check_binop(yystack_[1].location.begin.line, "<", natural, natural, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = binop_expression("<", boolean, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 874 "while.tab.cc"
    break;

  case 25: // expression: expression GR expression
#line 184 "while.y"
    {
        check_binop(yystack_[1].location.begin.line, ">", natural, natural, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = binop_expression(">", boolean, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 883 "while.tab.cc"
    break;

  case 26: // expression: expression LSE expression
#line 190 "while.y"
    {
        check_binop(yystack_[1].location.begin.line, "<=", natural, natural, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = binop_expression("<=", boolean, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 892 "while.tab.cc"
    break;

  case 27: // expression: expression GRE expression
#line 196 "while.y"
    {
        check_binop(yystack_[1].location.begin.line, ">=", natural, natural, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = binop_expression(">=", boolean, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 901 "while.tab.cc"
    break;

  case 28: // expression: expression AND expression
#line 202 "while.y"
    {
        check_binop(yystack_[1].location.begin.line, "and", boolean, boolean, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = binop_expression("and", boolean, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 910 "while.tab.cc"
    break;

  case 29: // expression: expression OR expression
#line 208 "while.y"
    {
        check_binop(yystack_[1].location.begin.line, "or", boolean, boolean, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = binop_expression("or", boolean, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 919 "while.tab.cc"
    break;

  case 30: // expression: expression EQ expression
#line 214 "while.y"
    {
        type typ = yystack_[2].value.as < expression > ().typ;
        check_binop(yystack_[1].location.begin.line, "=", typ, typ, yystack_[2].value.as < expression > ().typ, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = (typ == boolean) ?
                binop_expression("=boolean", boolean, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ()) :
                binop_expression("=natural", boolean, yystack_[2].value.as < expression > (), yystack_[0].value.as < expression > ());
    }
#line 931 "while.tab.cc"
    break;

  case 31: // expression: NOT expression
#line 223 "while.y"
    {
        check_uop(yystack_[0].location.begin.line, "not", boolean, yystack_[0].value.as < expression > ().typ);
        yylhs.value.as < expression > () = not_expression(yystack_[0].value.as < expression > ());
    }
#line 940 "while.tab.cc"
    break;

  case 32: // expression: OP expression CL
#line 229 "while.y"
    {
        yylhs.value.as < expression > () = yystack_[1].value.as < expression > ();
    }
#line 948 "while.tab.cc"
    break;

  case 33: // expression: FUNNAME BAR expression COMMA expression COMMA expression COMMA expression BAR
#line 234 "while.y"
    {
        // típus ellenőrzés
        check_my_fun(yystack_[9].location.begin.line, yystack_[7].value.as < expression > ().typ, yystack_[5].value.as < expression > ().typ, yystack_[3].value.as < expression > ().typ, yystack_[1].value.as < expression > ().typ);

        // kiértékelés
        yylhs.value.as < expression > () = function_expression(yystack_[7].value.as < expression > (), yystack_[5].value.as < expression > (), yystack_[3].value.as < expression > (), yystack_[1].value.as < expression > ());
    }
#line 960 "while.tab.cc"
    break;


#line 964 "while.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -36;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      -2,   -10,    13,   -36,   -36,    -1,   -36,    -6,    -5,   -36,
     130,   -36,   -36,   -36,     0,    18,    17,    17,    14,   -36,
      -3,    17,   -36,   -36,    17,   -36,   -36,    21,    17,    36,
      60,    17,    27,    78,    96,    17,   -36,   -36,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
     -36,   187,   -36,   -36,   -36,   149,   133,    48,   197,   206,
      66,    66,    66,    66,   -28,   -28,   -36,   -36,   -36,    35,
      17,   -36,   -36,   -36,   162,   140,    17,   -36,   175,    17,
     136,   -36
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,     1,     0,     7,     0,     0,     4,
       0,     5,     6,     2,     0,     0,     0,     0,     0,     8,
       0,     0,    16,    17,     0,    18,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,    11,     9,    10,    32,     0,     0,    29,    28,    30,
      24,    25,    26,    27,    19,    20,    21,    22,    23,     0,
       0,     7,    12,    14,     0,     0,     0,    13,     0,     0,
       0,    33
  };

  const signed char
  parser::yypgoto_[] =
  {
     -36,   -36,   -36,   -36,   -35,   -36,   -17
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     5,     9,    10,    19,    29
  };

  const signed char
  parser::yytable_[] =
  {
      30,     1,    56,     6,    33,     7,     8,    34,    47,    48,
      49,    36,     3,     4,    51,    69,    11,    12,    55,    32,
      20,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    31,    22,    23,    75,    24,    21,    25,
      26,    27,     0,    14,    15,    16,    35,    37,    52,    17,
       0,    73,     0,    74,     0,     0,    28,    18,     0,    78,
       0,     0,    80,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    53,
      45,    46,    47,    48,    49,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    54,     0,     0,
       0,     0,     0,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    13,     0,     0,    14,    15,
      16,    14,    15,    16,    17,    71,    72,    17,    14,    15,
      16,     0,    18,    77,    17,    18,     0,     0,     0,     0,
       0,    81,    18,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    70,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    76,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    79,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    41,    42,    43,    44,
      45,    46,    47,    48,    49
  };

  const signed char
  parser::yycheck_[] =
  {
      17,     3,    37,     4,    21,     6,     7,    24,    36,    37,
      38,    28,    22,     0,    31,    50,    22,    22,    35,    22,
      20,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    19,    17,    18,    71,    20,    20,    22,
      23,    24,    -1,     8,     9,    10,    25,    11,    21,    14,
      -1,    16,    -1,    70,    -1,    -1,    39,    22,    -1,    76,
      -1,    -1,    79,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    15,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    21,
      34,    35,    36,    37,    38,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,     5,    -1,    -1,     8,     9,
      10,     8,     9,    10,    14,    12,    13,    14,     8,     9,
      10,    -1,    22,    13,    14,    22,    -1,    -1,    -1,    -1,
      -1,    25,    22,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    30,    31,    32,    33,
      34,    35,    36,    37,    38
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    41,    22,     0,    42,     4,     6,     7,    43,
      44,    22,    22,     5,     8,     9,    10,    14,    22,    45,
      20,    20,    17,    18,    20,    22,    23,    24,    39,    46,
      46,    19,    22,    46,    46,    25,    46,    11,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      15,    46,    21,    21,    21,    46,    44,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    44,
      26,    12,    13,    16,    46,    44,    26,    13,    46,    26,
      46,    25
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    40,    41,    42,    42,    43,    43,    44,    44,    45,
      45,    45,    45,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     6,     0,     2,     2,     2,     0,     2,     4,
       4,     3,     5,     7,     5,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,    10
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PRG", "BEG", "END",
  "BOO", "NAT", "REA", "WRI", "IF", "THE", "ELS", "EIF", "WHI", "DO",
  "DON", "TRU", "FAL", "ASN", "OP", "CL", "ID", "NUM", "FUNNAME", "BAR",
  "COMMA", "OR", "AND", "EQ", "LS", "GR", "LSE", "GRE", "ADD", "SUB",
  "MUL", "DIV", "MOD", "NOT", "$accept", "start", "declarations",
  "declaration", "commands", "command", "expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    53,    53,    59,    62,    66,    71,    79,    83,    90,
      96,   101,   107,   113,   119,   127,   132,   137,   142,   147,
     153,   159,   165,   171,   177,   183,   189,   195,   201,   207,
     213,   222,   228,   233
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
    };
    // Last valid token kind.
    const int code_max = 294;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1399 "while.tab.cc"

#line 243 "while.y"

